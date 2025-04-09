/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athekkan <athekkan@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:54:29 by athekkan          #+#    #+#             */
/*   Updated: 2025/03/24 17:52:40 by athekkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	ft_puterror(char *str, t_error_type type)
{
	char	*prefix;

	if (type == ERROR)
		prefix = "\033[1;31mERROR: ";
	else
		prefix = "\033[1;33mWarning: ";
	ft_fprintf(2, "%s%s\033[0m\n", prefix, str);
	return (1);
}
