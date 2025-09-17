/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 06:25:38 by abazzoun          #+#    #+#             */
/*   Updated: 2025/09/17 14:17:59 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include <stdlib.h>

typedef struct s_node
{
	char			*str;
	struct s_node	*next;
}	t_node;

typedef struct s_list
{
	t_node	*head;
	t_node	*tail;
	size_t	len;
}	t_list;

t_list	*list_create(void);
void	list_destroy(t_list *lst);
int		list_addback(t_list *lst, char *str);
size_t	list_len(t_list *lst);

#endif
