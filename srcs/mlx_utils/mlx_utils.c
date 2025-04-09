/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athekkan <athekkan@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:10:27 by athekkan          #+#    #+#             */
/*   Updated: 2025/03/24 17:52:40 by athekkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_utils.h"

t_mlx	*t_mlx_init(unsigned int width, unsigned int height, char *title)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	mlx->instance = mlx_init();
	mlx->window = mlx_new_window(mlx->instance, width, height, title);
	mlx->img_list = NULL;
	mlx->sprite_list = NULL;
	return (mlx);
}

void	t_mlx_kill(t_mlx *mlx)
{
	t_list	*cursor;

	cursor = mlx->img_list;
	while (cursor)
	{
		free_image(mlx, cursor->content);
		cursor = cursor->next;
	}
	ft_lstclear(&mlx->img_list, NULL);
	ft_lstclear(&mlx->sprite_list, free);
	if (mlx->window)
		mlx_destroy_window(mlx->instance, mlx->window);
	mlx_destroy_display(mlx->instance);
	free(mlx->instance);
	free(mlx);
}
