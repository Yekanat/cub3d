/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athekkan <athekkan@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:53:20 by athekkan          #+#    #+#             */
/*   Updated: 2025/03/24 17:52:40 by athekkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strchrs(char *str, char *chrs)
{
	int	i;
	int	j;

	i = 0;
	if (str != NULL)
	{
		while (str[i])
		{
			j = 0;
			while (chrs[j])
			{
				if (str[i] == chrs[j])
					return (1);
				j++;
			}
			i++;
		}
	}
	return (0);
}
