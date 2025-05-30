/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athekkan <athekkan@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:24:53 by athekkan          #+#    #+#             */
/*   Updated: 2025/04/03 18:01:01 by athekkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	search_door(t_vars *vars)
{
	t_hit	hit;

	hit = cast_ray(vars->map, vars->player.pos, vars->player.angle, "D1O");
	if (hit.distance <= 1)
	{
		if (hit.collide_type == 'D')
			vars->map->data[hit.collide_cell.y][hit.collide_cell.x] = 'O';
		else if (hit.collide_type == 'O')
			vars->map->data[hit.collide_cell.y][hit.collide_cell.x] = 'D';
	}
	return (1);
}
