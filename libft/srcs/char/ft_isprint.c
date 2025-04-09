/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athekkan <athekkan@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:47:00 by athekkan          #+#    #+#             */
/*   Updated: 2024/11/04 13:47:00 by athekkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

// Checks for a printable character including space
int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
