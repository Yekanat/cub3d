/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athekkan <athekkan@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:09:58 by athekkan          #+#    #+#             */
/*   Updated: 2025/03/24 17:52:40 by athekkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

// Searches for `needle` in `str` within `n` characters
char	*ft_strnstr(const char *str, const char *needle, size_t n)
{
	size_t	i;
	size_t	needle_len;

	if (*needle == '\0')
		return ((char *)str);
	i = 0;
	needle_len = ft_strlen(needle);
	if (n < needle_len)
		return (NULL);
	while (str[i] && i < n - needle_len + 1)
	{
		if (ft_strncmp(str + i, needle, needle_len) == 0)
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}
