/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athekkan <athekkan@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:16:10 by athekkan          #+#    #+#             */
/*   Updated: 2025/03/24 17:52:40 by athekkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

// Return a substring from `str` starting at `start`, up to `len` characters
char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	i;
	size_t	src_len;

	src_len = ft_strlen(str);
	if (start >= src_len)
		len = 0;
	else if (len > src_len - start)
		len = src_len - start;
	new_str = malloc(sizeof(char) * (len + 1));
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (i < len && (str + start)[i])
	{
		new_str[i] = (str + start)[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
