/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_style.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athekkan <athekkan@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:24:13 by athekkan          #+#    #+#             */
/*   Updated: 2025/04/03 18:01:01 by athekkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static char	**get_style_adress(t_map *map, char **line)
{
	const char		*keys[] = {"NO", "SO", "WE", "EA", "F", "C"};
	const t_style	types[] = {NORTH, SOUTH, WEST, EAST, FLOOR, CEILING};
	int				i;
	char			**dest;
	size_t			key_len;

	i = 0;
	dest = NULL;
	while (i < (int)(sizeof(keys) / sizeof(keys[0])))
	{
		key_len = ft_strlen(keys[i]);
		if (ft_strncmp(*line, keys[i], key_len) == 0
			&& ft_isspace(*(*line + key_len)))
		{
			dest = &map->style[types[i]];
			*line = *line + key_len;
			break ;
		}
		i++;
	}
	return (dest);
}

int	add_style(t_map *map, char *line)
{
	char	**dest;

	dest = get_style_adress(map, &line);
	if (!dest)
		return (1);
	if (*dest)
	{
		ft_puterror("double key", ERROR);
		return (1);
	}
	while (*line && ft_isspace(*line))
		line++;
	if (line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	*dest = ft_strdup(line);
	return (0);
}
