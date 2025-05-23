/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_mouvement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athekkan <athekkan@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:12:02 by athekkan          #+#    #+#             */
/*   Updated: 2025/04/03 18:01:01 by athekkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	mouse_movement(t_vars *vars)
{
	int		x;
	int		y;
	int		delta_x;

	if (vars->inputs[ALT] == 1)
		return ;
	mlx_mouse_get_pos(vars->mlx->instance, vars->mlx->window, &x, &y);
	delta_x = x - W_WIDTH / 2;
	if (delta_x != 0)
	{
		vars->player.angle += delta_x * 0.002;
		x = W_WIDTH / 2;
		y = W_HEIGHT / 2;
		mlx_mouse_move(vars->mlx->instance, vars->mlx->window, x, y);
	}
}
