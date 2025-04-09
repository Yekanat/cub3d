/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athekkan <athekkan@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 21:15:58 by athekkan          #+#    #+#             */
/*   Updated: 2025/03/24 17:52:40 by athekkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_putchar(int fd, char c)
{
	return (write(fd, &c, 1));
}

int	ft_printf_putstr(int fd, char *str)
{
	int	i;

	if (str == NULL)
		return (ft_printf_putstr(fd, "(null)"));
	i = 0;
	while (str[i])
		i++;
	return (write(fd, str, i));
}

int	ft_printf_put_pointer(int fd, void *adress)
{
	if (adress == NULL)
		return (ft_printf_putstr(fd, "(nil)"));
	ft_printf_putstr(fd, "0x");
	return (2 + ft_printf_puthex(fd, (unsigned long)adress, HEX_BASE_L));
}
