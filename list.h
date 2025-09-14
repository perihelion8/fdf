/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 06:25:38 by abazzoun          #+#    #+#             */
/*   Updated: 2025/09/14 11:27:54 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

#include <stddef.h>

typedef struct s_list	t_list;

typedef struct s_cell
{
	int	z;
	int	color;
}	t_cell;

typedef struct s_grid
{
	t_cell	**cells;
	size_t	width;
	size_t	height;
}	t_grid;

t_list	*list_create(void);
void	list_destroy(t_list *lst);
int		list_addback(t_list *lst, char *str);
size_t	list_len(t_list *lst);
t_grid	*grid_create(t_list *lines);
void	grid_destroy(t_grid *grid);
void	grid_print(t_grid *grid);

#endif
