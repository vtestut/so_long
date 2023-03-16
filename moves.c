/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:38:44 by vtestut           #+#    #+#             */
/*   Updated: 2023/03/16 16:56:25 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

int	ft_hook_events(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		ft_close_and_free(vars);
	else if ((keycode == W_KEY || keycode == UP))
		ft_move_up(vars);
	else if ((keycode == S_KEY || keycode == DOWN))
		ft_move_down(vars);
	else if ((keycode == A_KEY || keycode == LEFT))
		ft_move_left(vars);
	else if ((keycode == D_KEY || keycode == RIGHT))
		ft_move_right(vars);
	ft_display_content(vars);
	return (0);
}

void	ft_move_up(t_vars *vars)
{
	int	x;
	int	y;

	x = vars->x_hero / vars->width;
	y = vars->y_hero / vars->height;
	if (vars->map_vars.map[y - 1][x] != '1')
	{
		if (vars->map_vars.map[y - 1][x] != 'E')
			ft_move_up_aux(vars, x, y);
		else if ((ft_check_collect(vars) == 0)
			&& (vars->map_vars.map[y - 1][x] == 'E'))
		{
			vars->map_vars.map[y - 1][x] = 'P';
			vars->map_vars.map[y][x] = '0';
			vars->moves++;
			ft_put_sprite(vars, vars->floor, y, x);
			ft_put_sprite(vars, vars->hero, y - 1, x);
			ft_printf("\nYou won ! total moves : %d.\n", vars->moves);
			ft_close_and_free(vars);
		}
	}
}

void	ft_move_down(t_vars *vars)
{
	int	x;
	int	y;

	x = vars->x_hero / vars->width;
	y = vars->y_hero / vars->height;
	if (vars->map_vars.map[y + 1][x] != '1')
	{
		if (vars->map_vars.map[y + 1][x] != 'E')
			ft_move_down_aux(vars, x, y);
		else if ((ft_check_collect(vars) == 0)
			&& (vars->map_vars.map[y + 1][x] == 'E'))
		{
			vars->map_vars.map[y + 1][x] = 'P';
			vars->map_vars.map[y][x] = '0';
			vars->moves++;
			ft_put_sprite(vars, vars->floor, y, x);
			ft_put_sprite(vars, vars->hero, y + 1, x);
			ft_printf("\nYou won ! total moves : %d.\n", vars->moves);
			ft_close_and_free(vars);
		}
	}
}

void	ft_move_left(t_vars *vars)
{
	int	x;
	int	y;

	x = vars->x_hero / vars->width;
	y = vars->y_hero / vars->height;
	if (vars->map_vars.map[y][x - 1] != '1')
	{
		if (vars->map_vars.map[y][x - 1] != 'E')
			ft_move_left_aux(vars, x, y);
		else if ((ft_check_collect(vars) == 0)
			&& (vars->map_vars.map[y][x - 1] == 'E'))
		{
			vars->map_vars.map[y][x - 1] = 'P';
			vars->map_vars.map[y][x] = '0';
			vars->moves++;
			ft_put_sprite(vars, vars->floor, y, x);
			ft_put_sprite(vars, vars->hero, y, x - 1);
			ft_printf("\nYou won ! total moves : %d.\n", vars->moves);
			ft_close_and_free(vars);
		}
	}
}

void	ft_move_right(t_vars *vars)
{
	int	x;
	int	y;

	x = vars->x_hero / vars->width;
	y = vars->y_hero / vars->height;
	if (vars->map_vars.map[y][x + 1] != '1')
	{
		if (vars->map_vars.map[y][x + 1] != 'E')
			ft_move_right_aux(vars, x, y);
		else if ((ft_check_collect(vars) == 0)
			&& (vars->map_vars.map[y][x + 1] == 'E'))
		{
			vars->map_vars.map[y][x + 1] = 'P';
			vars->map_vars.map[y][x] = '0';
			vars->moves++;
			ft_put_sprite(vars, vars->floor, y, x);
			ft_put_sprite(vars, vars->hero, y, x + 1);
			ft_printf("\nYou won ! total moves : %d.\n", vars->moves);
			ft_close_and_free(vars);
		}
	}
}
