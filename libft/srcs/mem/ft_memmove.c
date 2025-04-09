/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athekkan <athekkan@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:09:22 by athekkan          #+#    #+#             */
/*   Updated: 2025/03/24 17:52:40 by athekkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdint.h>

// Copies `n` bytes from `src` to `dest` handling overlaps safely
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	uint8_t	*d;
	uint8_t	*s;

	if (dest == src)
		return (dest);
	if (dest <= src)
		return (ft_memcpy(dest, src, n));
	d = (uint8_t *)dest + n;
	s = (uint8_t *)src + n;
	while (n >= 8)
	{
		d -= 8;
		s -= 8;
		*(uint64_t *)d = *(const uint64_t *)s;
		n -= 8;
	}
	while (n-- > 0)
		*--d = *--s;
	return (dest);
}
