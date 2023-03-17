/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 23:10:11 by vtestut           #+#    #+#             */
/*   Updated: 2023/03/17 14:54:07 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	ft_idle(t_vars *vars, int x, int y)
{
	static int	i;
	char		*moves;

	moves = ft_itoa(vars->moves);
	if (moves == NULL)
		ft_close_and_free(vars);
	i++;
	if (i == 60)
		i = 0;
	mlx_string_put(vars->mlx, vars->win, 32, 32, 0xFFFFFF, "moves :");
	mlx_string_put(vars->mlx, vars->win, 75, 32, 0xFFFFFF, moves);
	free(moves);
	if (i % 4 == 0)
		ft_put_sprite(vars, vars->hero1, y, x);
	else
		ft_put_sprite(vars, vars->hero2, y, x);
	usleep(60000);
	return (0);
}

void	ft_move_up_aux(t_vars *vars, int x, int y)
{
	if (vars->map_vars.map[y - 1][x] == 'M')
	{
		ft_printf("\nYou lose !\n\n");
		ft_close_and_free(vars);
	}
	vars->map_vars.map[y - 1][x] = 'P';
	vars->map_vars.map[y][x] = '0';
	vars->moves++;
	ft_put_sprite(vars, vars->floor, y, x);
	ft_bug_moves_up(vars);
	ft_display_content(vars);
}

void	ft_move_down_aux(t_vars *vars, int x, int y)
{
	if (vars->map_vars.map[y + 1][x] == 'M')
	{
		ft_printf("\nYou lose !\n\n");
		ft_close_and_free(vars);
	}
	vars->map_vars.map[y + 1][x] = 'P';
	vars->map_vars.map[y][x] = '0';
	vars->moves++;
	ft_put_sprite(vars, vars->floor, y, x);
	ft_bug_moves_down(vars);
	ft_display_content(vars);
}

void	ft_move_left_aux(t_vars *vars, int x, int y)
{
	if (vars->map_vars.map[y][x - 1] == 'M')
	{
		ft_printf("\nYou lose !\n\n");
		ft_close_and_free(vars);
	}
	vars->map_vars.map[y][x - 1] = 'P';
	vars->map_vars.map[y][x] = '0';
	vars->moves++;
	ft_put_sprite(vars, vars->floor, y, x);
	ft_bug_moves_left(vars);
	ft_display_content(vars);
}

void	ft_move_right_aux(t_vars *vars, int x, int y)
{
	if (vars->map_vars.map[y][x + 1] == 'M')
	{
		ft_printf("\nYou lose !\n\n");
		ft_close_and_free(vars);
	}
	vars->map_vars.map[y][x + 1] = 'P';
	vars->map_vars.map[y][x] = '0';
	vars->moves++;
	ft_put_sprite(vars, vars->floor, y, x);
	ft_bug_moves_right(vars);
	ft_display_content(vars);
}
