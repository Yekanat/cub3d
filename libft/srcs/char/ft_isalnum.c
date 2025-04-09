/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athekkan <athekkan@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:46:50 by athekkan          #+#    #+#             */
/*   Updated: 2024/11/04 13:46:50 by athekkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

// Checks for an alphanumeric character
int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
