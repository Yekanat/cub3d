/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athekkan <athekkan@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:43:34 by athekkan          #+#    #+#             */
/*   Updated: 2025/03/24 17:52:40 by athekkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

// Converts `nptr` to an interger (int)
int	ft_atoi(const char *nptr)
{
	long	result;
	int		sign;

	if (!nptr)
		return (0);
	result = 0;
	sign = 1;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
		if (*(nptr++) == '-')
			sign = -1;
	while (ft_isdigit(*nptr))
		result = result * 10 + (*(nptr++) - '0');
	return ((int)result * sign);
}
