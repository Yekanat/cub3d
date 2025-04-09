/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athekkan <athekkan@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:58:19 by athekkan          #+#    #+#             */
/*   Updated: 2024/11/05 09:44:32 by athekkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

// Allocates and returns a duplicate of `src`
char	*ft_strdup(const char *src)
{
	int		i;
	char	*dup;

	dup = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
