/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_to_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athekkan <athekkan@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 17:39:23 by athekkan          #+#    #+#             */
/*   Updated: 2025/03/24 17:52:40 by athekkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

// Create an array of pointers from a linked list
void	**ft_lst_to_array(t_list *lst)
{
	void	**array;
	size_t	i;

	array = ft_calloc(ft_lstsize(lst) + 1, sizeof(void *));
	if (!array)
		return (NULL);
	i = 0;
	while (lst)
	{
		array[i++] = lst->content;
		lst = lst->next;
	}
	return (array);
}
