/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 15:43:52 by abazzoun          #+#    #+#             */
/*   Updated: 2025/09/20 22:40:47 by abazzoun         ###   ########.fr       */
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

static t_cell	cell_make(char *str)
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

static t_grid	*grid_create(const char *file_name)
{
	t_grid	*grid;
	char	**split;
	int		fd;	
	size_t	i;

	grid = xmalloc(sizeof(*grid));
	fd = xopen(file_name);
	split = split_and_free_src(get_next_line(fd), ' ');
	grid->width = split_len(split);
	split_free(split);
	i = 1;
	while (try_free(get_next_line(fd)))
		i++;
	close(fd);
	grid->height = i;
	grid->cells = xmalloc(sizeof(t_cell *) * grid->height);
	i = 0;
	while (i < grid->height)
		grid->cells[i++] = xmalloc(sizeof(t_cell) * grid->width);
	return (grid);
}

t_grid	*parser_fdf_file(const char *file_name)
{
	char	**split;
	t_grid	*grid;
	int		fd;
	size_t	i;
	size_t	j;

	grid = grid_create(file_name);
	fd = xopen(file_name);
	i = 0;
	while (i < grid->height)
	{
		split = split_and_free_src(get_next_line(fd), ' ');
		j = 0;
		while (split[j])
		{
			grid->cells[i][j] = cell_make(split[j]);
			j++;
		}
		split_free(split);
		i++;
	}
	get_next_line(fd);
	close(fd);
	return (grid);
}
