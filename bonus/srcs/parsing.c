/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:24:32 by vtestut           #+#    #+#             */
/*   Updated: 2023/03/17 14:38:39 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

bool	ft_check_param(int ac, char **av, t_vars *vars)
{
	if (!ft_invalid_arg_num(ac))
		return (false);
	if (!ft_check_mapfile_format(av))
		return (false);
	if (!ft_is_file_empty(av))
		return (false);
	if (!ft_check_map(av, vars))
		ft_quit(vars);
	if (!ft_check_walls(vars))
		ft_quit(vars);
	if (!ft_check_content(vars))
		return (false);
	return (true);
}

bool	ft_invalid_arg_num(int ac)
{
	if (ac > 2)
	{
		ft_error("too many arguments");
		return (false);
	}
	else if (ac < 2)
	{
		ft_error("argument missing");
		return (false);
	}
	else
		return (true);
}

bool	ft_check_mapfile_format(char **av)
{
	int	map_file_len;

	map_file_len = ft_strlen(av[1]);
	if (!ft_strnstr(&av[1][map_file_len - 4], ".ber", 4))
	{
		ft_error("Wrong argument [.ber] FILE is required");
		return (false);
	}
	else
		return (true);
}

bool	ft_is_file_empty(char **av)
{
	int		fd;
	char	buffer[1];
	int		bytes_read;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		ft_error("While opening file");
		return (false);
	}
	bytes_read = read(fd, buffer, 1);
	close(fd);
	if (bytes_read == 0)
	{
		ft_error("Map file is empty");
		return (false);
	}
	else if (bytes_read < 0)
	{
		ft_error("While reading file");
		return (false);
	}
	return (true);
}

bool	ft_check_map(char **av, t_vars *vars)
{
	int			map_fd;
	int			read_return;
	char		*full;
	const int	read_s = (WIDTH_WINDOW / IMGSIZE + 1)
		* (HEIGHT_WINDOW / IMGSIZE + 1);

	full = malloc(sizeof(char) * read_s);
	if (full == NULL)
		return (ft_error("malloc() error !"), false);
	map_fd = open(av[1], O_RDONLY);
	if (map_fd == false)
		return (ft_error("open() error !"), ft_quit_early(vars, full));
	read_return = read(map_fd, full, read_s);
	if (read_return < 0)
		return (ft_error("read() error !"), ft_quit_early(vars, full));
	if (read_return >= read_s)
		return (ft_error("Map too big."), ft_quit_early(vars, full), false);
	full[read_return] = '\0';
	if (!(ft_check_map_2(full, read_return, vars)))
		return (false);
	if (!ft_check_map_3(full, vars))
		return (false);
	return (true);
}
