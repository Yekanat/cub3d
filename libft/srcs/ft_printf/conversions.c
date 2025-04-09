/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athekkan <athekkan@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:46:49 by athekkan          #+#    #+#             */
/*   Updated: 2025/03/24 17:52:40 by athekkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_puthex(int fd, unsigned long n, char *base)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += ft_printf_puthex(fd, n / 16, base);
	count += ft_printf_putchar(fd, base[n % 16]);
	return (count);
}

int	ft_printf_putnbr(int fd, int nb)
{
	int		count;
	long	nbr;

	count = 0;
	nbr = nb;
	if (nbr < 0)
	{
		count += write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr >= 10)
		count += ft_printf_putnbr(fd, nbr / 10);
	count += ft_printf_putchar(fd, nbr % 10 + '0');
	return (count);
}

int	ft_printf_putnbru(int fd, unsigned int nb)
{
	int				count;

	count = 0;
	if (nb >= 10)
		count += ft_printf_putnbru(fd, nb / 10);
	count += ft_printf_putchar(fd, nb % 10 + '0');
	return (count);
}
