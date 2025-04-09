/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athekkan <athekkan@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:47:29 by athekkan          #+#    #+#             */
/*   Updated: 2024/11/04 13:47:29 by athekkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

// Returns the length of the string `s`
size_t	ft_strlen(const char *s)
{
	int	count;

	count = 0;
	if (s)
		while (s[count] != '\0')
			count++;
	return (count);
}
