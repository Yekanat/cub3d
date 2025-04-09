/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athekkan <athekkan@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:11:27 by athekkan          #+#    #+#             */
/*   Updated: 2025/03/24 17:52:40 by athekkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

// Delete all nodes in the list, applying `del` to its content
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	if (!lst || !(*lst))
		return ;
	if ((*lst)->next)
		ft_lstclear(&((*lst)->next), del);
	ft_lstdelone(*lst, del);
	*lst = NULL;
}
