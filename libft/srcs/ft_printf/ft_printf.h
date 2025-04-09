/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athekkan <athekkan@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:46:23 by athekkan          #+#    #+#             */
/*   Updated: 2025/03/24 17:52:40 by athekkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# define HEX_BASE_L "0123456789abcdef"
# define HEX_BASE_U "0123456789ABCDEF"

int	ft_printf_putchar(int fd, char c);
int	ft_printf_putstr(int fd, char *str);
int	ft_printf_putnbr(int fd, int nb);
int	ft_printf_putnbru(int fd, unsigned int nb);
int	ft_printf_puthex(int fd, unsigned long n, char *base);
int	ft_printf_put_pointer(int fd, void *adress);

#endif