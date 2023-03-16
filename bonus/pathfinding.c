/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 05:29:53 by vtestut           #+#    #+#             */
/*   Updated: 2023/03/16 16:36:30 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

bool	ft_pathfinding(t_vars *vars)
{
	size_t	x;
	size_t	y;

	x = vars->x_hero;
	y = vars->y_hero;
	ft_backtracking(vars, x, y);
	if (is_finishable(vars) == false)
	{
		ft_error("Map can't be finish");
		ft_quit(vars);
	}
	return (true);
}

void	ft_backtracking(t_vars *vars, size_t x, size_t y)
{
	if (vars->map_vars.cloned_map[y][x] == '1')
		return ;
	else if (vars->map_vars.cloned_map[y][x] == '2')
		return ;
	else if (vars->map_vars.cloned_map[y][x] == 'M')
		return ;
	else if (vars->map_vars.cloned_map[y][x] == 'P')
		vars->map_vars.cloned_map[y][x] = '2';
	else if (vars->map_vars.cloned_map[y][x] == '0')
		vars->map_vars.cloned_map[y][x] = '2';
	else if (vars->map_vars.cloned_map[y][x] == 'C')
	{
		vars->map_vars.cloned_map[y][x] = '2';
		vars->map_vars.collectible_c++;
	}
	else if (vars->map_vars.cloned_map[y][x] == 'E')
	{
		vars->map_vars.exit_c++;
		vars->map_vars.cloned_map[y][x] = '1';
		return ;
	}
	ft_backtracking(vars, x + 1, y);
	ft_backtracking(vars, x, y + 1);
	ft_backtracking(vars, x - 1, y);
	ft_backtracking(vars, x, y - 1);
}

bool	is_finishable(t_vars *vars)
{
	if (vars->map_vars.collectible_c != vars->map_vars.collectible)
		return (false);
	if (vars->map_vars.exit_c != vars->map_vars.exit)
		return (false);
	return (true);
}

int	ft_check_collect(t_vars *vars)
{
	int	x;
	int	y;
	int	col;

	x = 0;
	y = 0;
	col = 0;
	while (vars->map_vars.map[y] != NULL)
	{
		while (vars->map_vars.map[y][x] != '\0')
		{
			if (vars->map_vars.map[y][x] == 'C')
				col++;
			x++;
		}
		x = 0;
		y++;
	}
	return (col);
}
