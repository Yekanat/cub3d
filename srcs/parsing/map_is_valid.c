/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_is_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athekkan <athekkan@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:15:09 by athekkan          #+#    #+#             */
/*   Updated: 2025/03/24 17:52:40 by athekkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "cub3D.h"

int	check_styles(t_map *map)
{
	int	styles;

	map->ceiling = convert_rgb(map, CEILING);
	map->floor = convert_rgb(map, FLOOR);
	styles = 0;
	styles |= check_style(map, NORTH);
	styles |= check_style(map, SOUTH);
	styles |= check_style(map, EAST);
	styles |= check_style(map, CEILING);
	styles |= check_style(map, FLOOR);
	return (styles);
}

int	map_incorrect_char(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	while (map->data[i])
	{
		j = 0;
		while (map->data[i][j])
		{
			if (ft_strchr(" D01NSEW\n", map->data[i][j]) == NULL)
				return (ft_puterror("invalid character in map", ERROR));
			j++;
		}
		i++;
	}
	return (0);
}

int	map_is_valid(t_map *map)
{
	if (check_styles(map) == 1)
		return (1);
	if (map->width == 0)
		return (ft_puterror("invalid map no floor / wall", ERROR));
	if (map->height <= 2 || map->width <= 2)
		return (ft_puterror("map too small", ERROR));
	if (map->start_pos.x == -1)
		return (ft_puterror("no player", ERROR));
	if (map_incorrect_char(map))
		return (1);
	if (check_map_data(map))
		return (1);
	fill_near(map->start_pos, 3, map);
	return (0);
}
