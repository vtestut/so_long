/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:59:51 by vtestut           #+#    #+#             */
/*   Updated: 2023/03/16 16:44:45 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

bool	ft_check_map_2(char *full, int read_return, t_vars *vars)
{
	int	i;

	i = 0;
	while (full[i] != '\0')
	{
		if (full[0] == '\n')
		{
			ft_error("empty line at begining of map file");
			ft_quit_early(vars, full);
		}
		else if (full[i] == '\n' && full[i + 1] == '\n')
		{	
			ft_error("empty line in middle of map file");
			ft_quit_early(vars, full);
		}
		else if (full[read_return - 1] == '\n')
		{
			ft_error("empty line at end of map file");
			ft_quit_early(vars, full);
		}
		i++;
	}
	return (true);
}

bool	ft_check_map_3(char *full, t_vars *vars)
{
	vars->map_vars.map = ft_split(full, '\n');
	vars->map_vars.cloned_map = ft_split(full, '\n');
	free(full);
	if (vars->map_vars.map == NULL || vars->map_vars.cloned_map == NULL)
		return (ft_error("ft_split failed"), false);
	if (!(ft_is_rectangle(vars)))
		return (false);
	return (true);
}

bool	ft_is_rectangle(t_vars *vars)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(vars->map_vars.map[0]);
	while (vars->map_vars.map[i] != NULL)
	{
		if (ft_strlen(vars->map_vars.map[i]) != len)
		{
			ft_error("Map shape is invalid");
			return (false);
		}
		i++;
		vars->map_vars.nb_of_rows++;
	}
	vars->map_vars.nb_of_cols = len;
	return (true);
}

bool	ft_check_walls(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->map_vars.map[0][i] != '\0')
	{
		if ((vars->map_vars.map[0][i] != '1')
			|| (vars->map_vars.map[vars->map_vars.nb_of_rows - 1][i] != '1'))
		{
			ft_error("Map must be surrounded by walls");
			return (false);
		}
		i++;
	}
	i = 0;
	while (vars->map_vars.map[i] != NULL)
	{
		if ((vars->map_vars.map[i][0] != '1')
			|| (vars->map_vars.map[i][vars->map_vars.nb_of_cols - 1] != '1'))
		{
			ft_error("Map must be surrounded by walls");
			return (false);
		}
		i++;
	}
	return (true);
}

bool	ft_check_content(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->map_vars.map[i] != NULL)
	{
		j = 0;
		while (vars->map_vars.map[i][j] != '\0')
		{
			if (ft_strchr("CPE01", vars->map_vars.map[i][j]) == NULL)
			{
				ft_error("Unvalide char in map file");
				ft_quit(vars);
			}
			j++;
		}
		i++;
	}
	ft_check_content_2(vars);
	if (!ft_check_content_3(vars))
		ft_quit(vars);
	return (true);
}
