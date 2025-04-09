/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athekkan <athekkan@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:52:17 by athekkan          #+#    #+#             */
/*   Updated: 2024/11/04 13:52:17 by athekkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

// If `c` is a lowercase letter, returns its uppercase equivalent
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}
