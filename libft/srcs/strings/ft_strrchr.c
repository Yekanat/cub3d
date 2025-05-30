/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athekkan <athekkan@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:10:01 by athekkan          #+#    #+#             */
/*   Updated: 2024/11/04 14:10:01 by athekkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

// Finds the last occurrence of `c` in `s`
char	*ft_strrchr(const char *s, int c)
{
	size_t	index;

	if (s != NULL)
	{
		index = ft_strlen(s);
		while (index && s[index] != (char)c)
			index--;
		if (s[index] == (char)c)
			return ((char *)&(s[index]));
	}
	return (NULL);
}
