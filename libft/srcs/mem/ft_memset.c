/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athekkan <athekkan@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:09:26 by athekkan          #+#    #+#             */
/*   Updated: 2025/03/24 17:52:40 by athekkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdint.h>

// Fills `n` bytes of `s` with the byte `c`
void	*ft_memset(void *dest, int value, size_t n)
{
	uint8_t		*d;
	uint64_t	block_value;
	uint8_t		byte_value;

	d = (uint8_t *)dest;
	byte_value = (uint8_t)value;
	block_value = (uint64_t)byte_value;
	block_value |= block_value << 8;
	block_value |= block_value << 16;
	block_value |= block_value << 32;
	while (n >= 8)
	{
		*(uint64_t *)d = block_value;
		d += 8;
		n -= 8;
	}
	while (n-- > 0)
		*d++ = byte_value;
	return (dest);
}
