/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athekkan <athekkan@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:59:41 by athekkan          #+#    #+#             */
/*   Updated: 2025/03/24 17:52:40 by athekkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

int	in_map(t_map *map, int x, int y)
{
	return (x >= 0 && y >= 0 && x < map->width && y < map->height);
}

int	check_collide(t_map *map, char *collide_set, int x, int y)
{
	return (! in_map(map, x, y) || ft_strchr(collide_set, map->data[y][x]));
}

t_cast_data	calc_cast(t_dpoint start, double angle)
{
	t_cast_data	data;

	data.start = start;
	data.angle = angle;
	data.tan_angle = tan(angle);
	data.step = (t_dpoint){CELL_SIZE, CELL_SIZE};
	if (cos(angle) <= 0)
		data.step.x *= -1;
	if (sin(angle) <= 0)
		data.step.y *= -1;
	data.v_hit.x = floor(start.x / CELL_SIZE) * CELL_SIZE;
	if (data.step.x > 0)
		data.v_hit.x += CELL_SIZE;
	data.v_hit.y = start.y + (data.v_hit.x - start.x) * data.tan_angle;
	data.h_hit.y = floor(start.y / CELL_SIZE) * CELL_SIZE;
	if (data.step.y > 0)
		data.h_hit.y += CELL_SIZE;
	data.h_hit.x = start.x + (data.h_hit.y - start.y) / data.tan_angle;
	return (data);
}
