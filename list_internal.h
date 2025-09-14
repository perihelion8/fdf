/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_internal.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 06:26:19 by abazzoun          #+#    #+#             */
/*   Updated: 2025/09/14 11:48:33 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_INTERNAL_H
# define LIST_INTERNAL_H

#include <stdio.h>
# include "list.h"

typedef struct s_node
{
	char			*str;
	struct s_node	*next;
}	t_node;

struct s_list
{
	t_node	*head;
	t_node	*tail;
	size_t	len;
};

void	free_split(char **split);
int		hextoi(const char *str);

#endif
