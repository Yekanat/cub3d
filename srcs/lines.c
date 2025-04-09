/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athekkan <athekkan@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:38:16 by athekkan          #+#    #+#             */
/*   Updated: 2025/03/24 17:52:40 by athekkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	draw_vline(t_img *dest, t_point p, int h, int color)
{
	int	i;

	i = 0;
	while (i < h)
		put_pixel(dest, p.x, p.y + i++, color);
}

void	draw_hline(t_img *dest, t_point p, int l, int color)
{
	int	i;

	i = 0;
	while (i < l)
		put_pixel(dest, p.x + i++, p.y, color);
}
