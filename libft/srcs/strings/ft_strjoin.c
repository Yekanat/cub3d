/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athekkan <athekkan@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:15:13 by athekkan          #+#    #+#             */
/*   Updated: 2025/03/24 17:52:40 by athekkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

// Concatenates `s1` and `s2` into a new string
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	int		i;

	new_str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (*s1)
		new_str[i++] = *(s1++);
	while (*s2)
		new_str[i++] = *(s2++);
	new_str[i] = '\0';
	return (new_str);
}
