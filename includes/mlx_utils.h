/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athekkan <athekkan@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:27:51 by athekkan          #+#    #+#             */
/*   Updated: 2025/03/24 17:52:40 by athekkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_UTILS_H
# define MLX_UTILS_H

# include <libft.h>
# include <mlx.h>

# define TORCH_SIZE 6

typedef struct s_img
{
	int		width;
	int		height;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_mlx
{
	void	*instance;
	void	*window;
	t_list	*img_list;
	t_list	*sprite_list;
}	t_mlx;

t_mlx	*t_mlx_init(unsigned int width, unsigned int height, char *title);
void	t_mlx_kill(t_mlx *mlx);

void	free_image(t_mlx *mlx, t_img *img);
void	clear_array_img(t_mlx *mlx, t_img **imgs);
t_img	*new_image(t_mlx *mlx, int width, int height);
t_img	*load_img(t_mlx *mlx, char *path);
t_img	**load_sprites(t_mlx *mlx, char *path, unsigned int count);

void	put_pixel(t_img *img, int x, int y, int color);
void	put_image(t_img *dest, t_img *img, int x0, int y0);
int		get_pixel(t_img *img, int x, int y);
void	put_resized_pixel(t_img *dest, int offx, int offy, int color);
void	put_image_resized(t_img *dest, t_img *img, int x0, int y0);

#endif