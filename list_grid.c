/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 08:59:52 by abazzoun          #+#    #+#             */
/*   Updated: 2025/09/14 14:47:39 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_internal.h"
#include "libft.h"

static size_t	grid_width(char *line)
{
	size_t	i;
	char	**split;

	split = ft_split(line, ' ');
	i = 0;
	while (split[i])
		i++;
	free_split(split);
	return (i);
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
		cell.color = 0x0000FF;
	return (cell);
}

static void	fill_grid(t_grid *grid, t_list *lines)
{
	t_node	*node;
	char	**split;
	size_t	i;
	size_t	j;
	
	node = lines->head;
	i = 0;
	while (node)
	{
		split = ft_split(node->str, ' '); 
		j = 0;
		while (split[j])
		{
			grid->cells[i][j] = cell_new(split[j]);
			j++;
		}
		i++;
		node = node->next;
		free_split(split);
	}
}

t_grid	*grid_create(t_list *lines)
{
	t_grid	*grid;
	size_t	i;

	grid = malloc(sizeof(t_grid));
	if (!grid)
		return (NULL);
	grid->height = list_len(lines);
	grid->width = grid_width(lines->head->str);
	grid->cells = malloc(sizeof(t_cell *) * grid->height);
	if (!grid->cells)
	{
		grid_destroy(grid);
		return (NULL);
	}
	i = 0;
	while (i < grid->height)
	{
		grid->cells[i] = malloc(sizeof(t_cell) * grid->width);
		if (!grid->cells[i])
		{
			grid_destroy(grid);
			return (NULL);
		}
		i++;
	}
	fill_grid(grid, lines);
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
