/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 15:43:52 by abazzoun          #+#    #+#             */
/*   Updated: 2025/09/20 18:54:44 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	xopen(const char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	return (fd);
}

static void	free_split(char **split)
{
	size_t	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static t_cell	cell_make(char *str)
{
	t_cell	cell;
	char		*commaptr;

	commaptr = ft_strchr(str, ',');
	cell.z = ft_atoi(str);
	if (commaptr)
		cell.color = hextoi(commaptr + 1);
	else
		cell.color = 0xFFFFFF;
	return (cell);
}

static t_grid *grid_create(const char *file_name)
{
	t_grid	*grid;
	int			fd;	
	char		**split;
	size_t	i;

	grid = xmalloc(sizeof(*grid));
	fd = xopen(file_name);
	split = ft_split(get_next_line(fd), ' ');
	i = 0;
	while (split[i])
		i++;
	free_split(split);
	grid->width = i;
	i = 1;
	while (get_next_line(fd))
		i++;
	grid->height = i;
	close(fd);
	grid->cells = xmalloc(sizeof(t_cell *) * grid->height);	
	i = 0;
	while (i < grid->height)
		grid->cells[i++] = xmalloc(sizeof(t_cell) * grid->width);
	return (grid);
}

t_grid	*parser_fdf_file(const char *file_name)
{
	char		**split;
	t_grid	*grid;
	int			fd;
	size_t	i;
	size_t	j;

	grid = grid_create(file_name);
	fd = xopen(file_name);
	i = 0;
	while (i < grid->height)
	{
		split = ft_split(get_next_line(fd), ' ');
		j = 0;
		while (split[j])
		{
			grid->cells[i][j] = cell_make(split[j]);
			j++;
		}
		free_split(split);
		i++;
	}
	close(fd);
	return (grid);
}
