/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_dup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athekkan <athekkan@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:39:25 by athekkan          #+#    #+#             */
/*   Updated: 2025/04/03 18:01:01 by athekkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_point	find_player(char **map)
{
	t_point	player;

	player.y = 0;
	while (map[player.y])
	{
		player.x = 0;
		while (map[player.y][player.x])
		{
			if (ft_strchr("NSEW", map[player.y][player.x]))
				return (player);
			player.x++;
		}
		player.y++;
	}
	player.x = -1;
	player.y = -1;
	return (player);
}

char	*line_dup(const char *src, int len)
{
	int		i;
	char	*dup;

	dup = malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (src[i] && i < len)
	{
		if (src[i] == '\n')
			dup[i] = ' ';
		else
			dup[i] = src[i];
		i++;
	}
	while (i < len)
	{
		dup[i] = ' ';
		i++;
	}
	dup[len] = '\0';
	return (dup);
}
