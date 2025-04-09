/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athekkan <athekkan@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:09:32 by athekkan          #+#    #+#             */
/*   Updated: 2024/11/04 14:09:32 by athekkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

// Finds the first occurrence of `c` in `s`
char	*ft_strchr(const char *s, int c)
{
	if (s != NULL)
	{
		while (*s && *s != (char)c)
			s++;
		if (*s == (char)c)
			return ((char *)s);
	}
	return (NULL);
}
