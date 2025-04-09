/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athekkan <athekkan@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:16:30 by athekkan          #+#    #+#             */
/*   Updated: 2025/03/24 17:52:40 by athekkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

// Removes characters in `set` from the beginning and end of `str`
char	*ft_strtrim(char const *str, char const *set)
{
	int		i;

	while (*str && ft_strchr(set, *str))
		str++;
	i = ft_strlen(str) - 1;
	while (i > 0 && ft_strrchr(set, str[i]))
		i--;
	return (ft_substr(str, 0, i + 1));
}
