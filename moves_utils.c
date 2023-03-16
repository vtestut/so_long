/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 23:10:11 by vtestut           #+#    #+#             */
/*   Updated: 2023/03/08 17:42:02 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

void	ft_move_up_aux(t_vars *vars, int x, int y)
{
	vars->map_vars.map[y - 1][x] = 'P';
	vars->map_vars.map[y][x] = '0';
	vars->moves++;
	ft_put_sprite(vars, vars->floor, y, x);
	ft_printf("\rmoves = [%d]", vars->moves);
	ft_display_content(vars);
}

void	ft_move_down_aux(t_vars *vars, int x, int y)
{
	vars->map_vars.map[y + 1][x] = 'P';
	vars->map_vars.map[y][x] = '0';
	vars->moves++;
	ft_put_sprite(vars, vars->floor, y, x);
	ft_printf("\rmoves = [%d]", vars->moves);
	ft_display_content(vars);
}

void	ft_move_left_aux(t_vars *vars, int x, int y)
{
	vars->map_vars.map[y][x - 1] = 'P';
	vars->map_vars.map[y][x] = '0';
	vars->moves++;
	ft_put_sprite(vars, vars->floor, y, x);
	ft_printf("\rmoves = [%d]", vars->moves);
	ft_display_content(vars);
}

void	ft_move_right_aux(t_vars *vars, int x, int y)
{
	vars->map_vars.map[y][x + 1] = 'P';
	vars->map_vars.map[y][x] = '0';
	vars->moves++;
	ft_put_sprite(vars, vars->floor, y, x);
	ft_printf("\rmoves = [%d]", vars->moves);
	ft_display_content(vars);
}
