/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athekkan <athekkan@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 10:55:50 by athekkan          #+#    #+#             */
/*   Updated: 2025/03/24 17:52:40 by athekkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#define FILE_EXT ".cub"

int	open_file(char *path)
{
	int	index;
	int	fd;

	index = ft_strlen(path) - ft_strlen(FILE_EXT);
	if (index < 0 || ft_strcmp(path + index, FILE_EXT))
		return (-1);
	fd = open(path, O_RDONLY);
	return (fd);
}
