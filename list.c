/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 08:33:54 by abazzoun          #+#    #+#             */
/*   Updated: 2025/09/14 12:01:41 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "list_internal.h"

static t_node	*list_node_new(char *str)
{
	t_node	*node;

	node = malloc(sizeof(*node));
	if (!node)
		return (NULL);
	node->str = str;
	node->next = NULL;
	return (node);
}

t_list	*list_create(void)
{
	t_list	*lst;

	lst = malloc(sizeof(*lst));
	if (!lst)
		return (NULL);
	lst->head = NULL;
	lst->tail = NULL;
	lst->len = 0;
	return (lst);
}

void	list_destroy(t_list *lst)
{
	t_node	*tmp;

	if (!lst)
		return ;
	tmp = lst->head;
	while (lst->head)
	{
		free(lst->head->str);
		tmp = lst->head;
		lst->head = lst->head->next;
		free(tmp);
	}
}

size_t	list_len(t_list *lst)
{
	return (lst->len);
}

int	list_addback(t_list *lst, char *str)
{
	t_node	*new;

	if (!str)
		return (-1);
	new = list_node_new(str);
	if (!new)
		return (-1);
	if (!lst->head)
	{
		lst->head = new;
		lst->tail = new;
	}
	else
	{
		lst->tail->next = new;
		lst->tail = lst->tail->next;
	}
	lst->len++;
	return (0);
}
