/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:32:57 by vtestut           #+#    #+#             */
/*   Updated: 2023/03/16 16:54:54 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

void	ft_check_content_2(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->map_vars.map[i] != NULL)
	{
		j = 0;
		while (vars->map_vars.map[i][j] != '\0')
		{
			if (vars->map_vars.map[i][j] == 'P')
			{
				vars->map_vars.player++;
				vars->y_hero = i;
				vars->x_hero = j;
			}
			else if (vars->map_vars.map[i][j] == 'C')
				vars->map_vars.collectible++;
			else if (vars->map_vars.map[i][j] == 'E')
				vars->map_vars.exit++;
			j++;
		}
		i++;
	}
}

bool	ft_check_content_3(t_vars *vars)
{
	if (vars->map_vars.player != 1)
		return (ft_error("Wrong number of player. 1 is required"), false);
	if (vars->map_vars.collectible < 1)
		return (ft_error("No collectible"), false);
	if (vars->map_vars.exit != 1)
		return (ft_error("Wrong number of exit. 1 is required"), false);
	return (true);
}
