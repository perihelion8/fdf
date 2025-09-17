/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 22:28:22 by abazzoun          #+#    #+#             */
/*   Updated: 2025/09/17 18:46:59 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_grid	*grid_new(t_list *lines)
{
	t_grid	*grid;
	size_t	i;
	char	**split;

	split = ft_split(lines->head->str, ' ');
	i = 0;
	while (split[i])
		i++;
	free_split(split);
	grid = xmalloc(sizeof(*grid));
	grid->cells = xmalloc(sizeof(t_cell *) * i);
	grid->width = i;
	grid->height = list_len(lines);
	return (grid);
}

static t_cell	cell_new(char *str)
{
	t_cell	cell;
	char	*commaptr;

	commaptr = ft_strchr(str, ',');
	cell.z = ft_atoi(str);
	if (commaptr)
		cell.color = hextoi(commaptr + 1);
	else
		cell.color = 0xFFFFFF;
	return (cell);
}

t_grid	*lines_to_grid(t_list *lines)
{
	t_node	*node;
	t_grid	*grid;
	char	**split;
	size_t	i;
	size_t	j;

	grid = grid_new(lines);
	node = lines->head;
	i = 0;
	while (i < grid->height)
	{
		grid->cells[i] = xmalloc(sizeof(t_cell) * grid->width);
		split = ft_split(node->str, ' ');
		j = 0;
		while (split[j])
		{
			grid->cells[i][j] = cell_new(split[j]);
			j++;
		}
		free_split(split);
		node = node->next;
		i++;
	}
	return (grid);
}

void	grid_destroy(t_grid *grid)
{
	size_t	i;

	if (!grid)
		return ;
	if (grid->cells)
	{
		i = 0;
		while (i < grid->height)
		{
			if (grid->cells[i])
				free(grid->cells[i]);
			i++;
		}
		free(grid->cells);
	}
	free(grid);
}
