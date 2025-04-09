/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_before.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athekkan <athekkan@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:46:09 by athekkan          #+#    #+#             */
/*   Updated: 2025/03/24 17:52:40 by athekkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

// Add `new` before the node `lst`
void	ft_lstadd_before(t_list **lst, t_list *new)
{
	t_list	*prev_node;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	prev_node = (*lst)->prev;
	new->next = *lst;
	(*lst)->prev = new;
	new->prev = prev_node;
	if (prev_node)
		prev_node->next = new;
}
