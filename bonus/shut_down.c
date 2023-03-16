/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shut_down.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:00:41 by vtestut           #+#    #+#             */
/*   Updated: 2023/03/09 02:59:57 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

void	ft_destroy_image(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->hero1);
	mlx_destroy_image(vars->mlx, vars->hero2);
	mlx_destroy_image(vars->mlx, vars->wall);
	mlx_destroy_image(vars->mlx, vars->floor);
	mlx_destroy_image(vars->mlx, vars->coffee);
	mlx_destroy_image(vars->mlx, vars->exit);
	mlx_destroy_image(vars->mlx, vars->exit2);
	mlx_destroy_image(vars->mlx, vars->bug_v.bug1);
	mlx_destroy_image(vars->mlx, vars->bug_v.bug2);
}

int	ft_close_and_free(t_vars *vars)
{
	int	i;

	i = 0;
	if (vars->map_vars.map != NULL)
	{
		while (vars->map_vars.map[i] != NULL)
		{
			free(vars->map_vars.map[i]);
			free(vars->map_vars.cloned_map[i]);
			i++;
		}
		ft_destroy_image(vars);
		mlx_destroy_window(vars->mlx, vars->win);
		free(vars->map_vars.map);
		free(vars->map_vars.cloned_map);
	}
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);
}

int	ft_quit(t_vars *vars)
{
	int	i;

	i = 0;
	if (vars->map_vars.map != NULL)
	{
		while (vars->map_vars.map[i] != NULL)
		{
			free(vars->map_vars.map[i]);
			free(vars->map_vars.cloned_map[i]);
			i++;
		}
		free(vars->map_vars.map);
		free(vars->map_vars.cloned_map);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
	exit(0);
}

int	ft_quit_early(t_vars *vars, char *full)
{
	free(full);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);
}

void	ft_error(char *str)
{
	ft_printf("Error\n%s\n", str);
}
