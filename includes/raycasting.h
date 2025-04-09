/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athekkan <athekkan@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:49:37 by athekkan          #+#    #+#             */
/*   Updated: 2025/03/24 17:50:37 by athekkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

typedef struct s_cast_data
{
	t_dpoint	start;
	double		angle;
	double		tan_angle;
	t_dpoint	step;
	t_dpoint	v_hit;
	t_dpoint	h_hit;
}	t_cast_data;

int			in_map(t_map *map, int x, int y);

int			check_collide(t_map *map, char *collide_set, int x, int y);

t_cast_data	calc_cast(t_dpoint start, double angle);