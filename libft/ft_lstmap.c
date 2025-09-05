/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:26:27 by a                 #+#    #+#             */
/*   Updated: 2025/06/05 16:52:28 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	mapped_list_destroy(t_list **mapped_list, void (*del)(void *))
{
	if (mapped_list == NULL || del == NULL)
		return ;
	ft_lstclear(mapped_list, del);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*mapped_list;
	t_list	*mapped_node;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	mapped_list = NULL;
	while (lst)
	{
		mapped_node = ft_lstnew(f(lst->content));
		if (mapped_node == NULL)
		{
			mapped_list_destroy(&mapped_list, del);
			return (NULL);
		}
		ft_lstadd_back(&mapped_list, mapped_node);
		lst = lst->next;
	}
	return (mapped_list);
}
