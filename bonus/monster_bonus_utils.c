/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 03:35:11 by vtestut           #+#    #+#             */
/*   Updated: 2023/03/09 03:36:31 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

int	ft_bug_idle(t_vars *vars, int x, int y)
{
	static int	i;

	i++;
	if (i == 60)
		i = 0;
	if (i % 4 == 0)
		ft_put_sprite(vars, vars->bug_v.bug1, y, x);
	else
		ft_put_sprite(vars, vars->bug_v.bug2, y, x);
	return (0);
}
