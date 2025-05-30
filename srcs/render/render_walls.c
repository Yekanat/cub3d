/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athekkan <athekkan@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:10:42 by athekkan          #+#    #+#             */
/*   Updated: 2025/03/24 17:52:40 by athekkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

double	segment_size(double distance)
{
	return ((double)W_WIDTH / (2 * tan((FOV * PI / 180) / 2)) / distance);
}

int	get_pixel_scale(t_img *img, int x, int y, int size)
{
	return (get_pixel(img, x * img->width / CELL_SIZE, y * img->height / size));
}

void	draw_wall_segment(t_vars *vars, int ray_index, t_hit hit, int size)
{
	int		i;
	int		j;
	int		color;
	t_img	*texture;

	texture = vars->textures[hit.side];
	if (hit.collide_type == 'D')
		texture = vars->door_texture;
	if (size <= W_HEIGHT)
	{
		i = 0;
		j = size;
	}
	else
	{
		i = (size - W_HEIGHT) / 2;
		j = W_HEIGHT + i;
	}
	while (i < j)
	{
		color = get_pixel_scale(texture, hit.col_index, i, size);
		if (vars->shadow)
			color = color_shadowing(color, hit.distance);
		put_pixel(vars->buffer, ray_index, i++ + (W_HEIGHT - size) / 2, color);
	}
}

void	draw_walls(t_vars *vars)
{
	int			i;
	double		camera_x;
	double		ray_angle;
	t_hit		hit;
	int			size;

	i = 0;
	while (i < W_WIDTH)
	{
		camera_x = (2.0 * i / (W_WIDTH - 1)) - 1.0;
		ray_angle = vars->player.angle
			+ atan(camera_x * tan((FOV * PI / 180) / 2));
		hit = cast_ray(vars->map, vars->player.pos, ray_angle, "D1");
		size = segment_size(hit.distance * cos(ray_angle - vars->player.angle));
		draw_wall_segment(vars, i, hit, size);
		i++;
	}
}
