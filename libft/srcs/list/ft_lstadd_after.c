/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_after.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athekkan <athekkan@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:46:09 by athekkan          #+#    #+#             */
/*   Updated: 2025/03/24 17:52:40 by athekkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

// Add `new` after the node `lst`
void	ft_lstadd_after(t_list **lst, t_list *new)
{
	t_list	*next_node;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	next_node = (*lst)->next;
	(*lst)->next = new;
	new->prev = *lst;
	new->next = next_node;
	if (next_node)
		next_node->prev = new;
}
