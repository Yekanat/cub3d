/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athekkan <athekkan@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:39:28 by athekkan          #+#    #+#             */
/*   Updated: 2025/03/24 17:52:40 by athekkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	is_empty_line(char *line)
{
	while (*line && ft_isspace(*line))
		line++;
	return (!*line);
}

static void	set_player(t_map *map)
{
	char	player_char;

	map->start_pos = find_player(map->data);
	if (map->start_pos.x < 0)
		return ;
	player_char = map->data[map->start_pos.y][map->start_pos.x];
	if (player_char == 'N')
		map->start_dir = 3 * PI / 2;
	if (player_char == 'E')
		map->start_dir = 0;
	if (player_char == 'S')
		map->start_dir = PI / 2;
	if (player_char == 'W')
		map->start_dir = PI;
}

static void	fill_data(t_map *map, t_list *lst)
{
	t_list	*head;
	int		len;
	int		new_len;
	int		i;

	head = lst;
	len = 0;
	while (lst)
	{
		new_len = ft_strlen(lst->content);
		if (ft_strchrs(lst->content, "10") && new_len > len)
			len = new_len;
		lst = lst->next;
	}
	map->width = len;
	lst = head;
	i = 0;
	while (lst)
	{
		map->data[i] = line_dup((char *) lst->content, map->width);
		map->discovered[i] = line_dup((char *) lst->content, map->width);
		i++;
		lst = lst->next;
	}
	set_player(map);
}

t_map	*list_to_map(t_list *lst)
{
	t_map	*map;
	int		in_map;

	map = ft_calloc(1, sizeof(t_map));
	in_map = 0;
	while (lst && !in_map)
	{
		if (in_map == 0 && add_style(map, lst->content))
		{
			if (!is_empty_line(lst->content))
			{
				in_map = 1;
				break ;
			}
		}
		lst = lst->next;
	}
	if (!in_map)
		return (free_map(map), NULL);
	map->height = ft_lstsize(lst);
	map->data = ft_calloc(map->height + 1, sizeof(char *));
	map->discovered = ft_calloc(map->height + 1, sizeof(char *));
	fill_data(map, lst);
	return (map);
}
