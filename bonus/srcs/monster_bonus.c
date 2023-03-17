/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:46:08 by vtestut           #+#    #+#             */
/*   Updated: 2023/03/17 14:53:30 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

bool	ft_bug_can_go(t_vars *vars, int y, int x)
{
	if (vars->map_vars.map[y][x] == '1')
		return (false);
	else if (vars->map_vars.map[y][x] == 'M')
		return (false);
	else if (vars->map_vars.map[y][x] == 'C')
		return (false);
	else if (vars->map_vars.map[y][x] == 'E')
		return (false);
	else if (vars->map_vars.map[y][x] == 'P')
		return (true);
	else if (vars->map_vars.map[y][x] == '0')
		return (true);
	return (false);
}

void	ft_bug_moves_up(t_vars *vars)
{
	int	x;
	int	y;

	x = vars->bug_v.x_bug;
	y = vars->bug_v.y_bug;
	if ((ft_bug_can_go(vars, y + 1, x)) && vars->map_vars.map[y + 1][x] == 'P')
	{
		ft_printf("\nYou lose !\n\n");
		ft_close_and_free(vars);
	}
	if (ft_bug_can_go(vars, y + 1, x))
	{
		ft_put_sprite(vars, vars->floor, y, x);
		ft_put_sprite(vars, vars->bug_v.bug1, y + 1, x);
		vars->map_vars.map[y][x] = '0';
		vars->map_vars.map[y + 1][x] = 'M';
		vars->bug_v.y_bug = y + 1;
	}
	else
		return ;
}

void	ft_bug_moves_down(t_vars *vars)
{
	int	x;
	int	y;

	x = vars->bug_v.x_bug;
	y = vars->bug_v.y_bug;
	if ((ft_bug_can_go(vars, y - 1, x)) && vars->map_vars.map[y - 1][x] == 'P')
	{
		ft_printf("\nYou lose !\n\n");
		ft_close_and_free(vars);
	}
	if (ft_bug_can_go(vars, y - 1, x))
	{
		ft_put_sprite(vars, vars->floor, y, x);
		ft_put_sprite(vars, vars->bug_v.bug1, y - 1, x);
		vars->map_vars.map[y][x] = '0';
		vars->map_vars.map[y - 1][x] = 'M';
		vars->bug_v.y_bug = y - 1;
	}
	else
		return ;
}

void	ft_bug_moves_left(t_vars *vars)
{
	int	x;
	int	y;

	x = vars->bug_v.x_bug;
	y = vars->bug_v.y_bug;
	if ((ft_bug_can_go(vars, y, x + 1)) && vars->map_vars.map[y][x + 1] == 'P')
	{
		ft_printf("\nYou lose !\n\n");
		ft_close_and_free(vars);
	}
	if (ft_bug_can_go(vars, y, x + 1))
	{
		ft_put_sprite(vars, vars->floor, y, x);
		ft_put_sprite(vars, vars->bug_v.bug1, y, x + 1);
		vars->map_vars.map[y][x] = '0';
		vars->map_vars.map[y][x + 1] = 'M';
		vars->bug_v.x_bug = x + 1;
	}
	else
		return ;
}

void	ft_bug_moves_right(t_vars *vars)
{
	int	x;
	int	y;

	x = vars->bug_v.x_bug;
	y = vars->bug_v.y_bug;
	if ((ft_bug_can_go(vars, y, x - 1)) && vars->map_vars.map[y][x - 1] == 'P')
	{	
		ft_printf("\nYou lose !\n\n");
		ft_close_and_free(vars);
	}
	if (ft_bug_can_go(vars, y, x - 1))
	{
		ft_put_sprite(vars, vars->floor, y, x);
		ft_put_sprite(vars, vars->bug_v.bug1, y, x - 1);
		vars->map_vars.map[y][x] = '0';
		vars->map_vars.map[y][x - 1] = 'M';
		vars->bug_v.x_bug = x - 1;
	}
	else
		return ;
}
