/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athekkan <athekkan@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:09:15 by athekkan          #+#    #+#             */
/*   Updated: 2025/03/24 17:52:40 by athekkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdint.h>

// Copies `n` bytes from `src` to `dest`
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	uint8_t	*d;
	uint8_t	*s;

	d = (uint8_t *)dest;
	s = (uint8_t *)src;
	while (n >= 8)
	{
		*(uint64_t *)d = *(const uint64_t *)s;
		d += 8;
		s += 8;
		n -= 8;
	}
	while (n-- > 0)
		*d++ = *s++;
	return (dest);
}
