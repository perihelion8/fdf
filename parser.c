/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 21:32:27 by abazzoun          #+#    #+#             */
/*   Updated: 2025/09/12 23:16:36 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static size_t	split_size(char **split)
{
	size_t	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

static t_arri	*parse_line(int fd)
{
	t_arri	*row;
	char	**split;
	char	*line;
	size_t	i;

	line = get_next_line(fd);
	if (!line)
		return (NULL);
	split = ft_split(line, ' ');
	if (!split)
		return (NULL);
	free(line);
	row = xmalloc(sizeof(*row));
	row->size = split_size(split);
	row->data = xmalloc(sizeof(int) * row->size);
	i = 0;
	while (split[i])
	{
		row->data[i] = ft_atoi(split[i]);
		i++;
	}
	free_split(split);
	return (row);
}

static t_map	*init_map(t_list *rows)
{
	t_map	*map;
	t_arri	*arri;
	t_list	*rowsp;
	size_t	i;

	i = 0;
	rowsp = rows;
	while (rowsp)
	{
		i++;
		rowsp = rowsp->next;
	}
	map = xmalloc(sizeof(*map));
	map->height = i;
	arri = rows->content;
	map->width = arri->size;
	map->cells = xmalloc(sizeof(int *) * map->height);
	i = 0;
	while (i < map->height)
	{
		map->cells[i] = xmalloc(sizeof(int) * map->width);
		i++;
	}
	return (map);
}

static t_map	*rows_to_map(t_list *rows)
{
	t_map	*map;
	t_list	*rowsp;
	t_arri	*arri;
	size_t	i;
	size_t	j;

	map = init_map(rows);
	i = 0;
	rowsp = rows;
	while (rowsp)
	{
		j = 0;
		while (j < map->width)
		{
			arri = rowsp->content;
			map->cells[i][j] = arri->data[j];
			j++;
		}
		i++;
		rowsp = rowsp->next;
	}
	return (map);
}

t_map	*parse_fdf(const char *file_name)
{
	t_list	*rows;
	t_arri	*row;
	t_map	*map;
	int		fd;

	fd = open(file_name, O_RDONLY);
	if (!fd)
	{
		perror("open failed");
		exit(EXIT_FAILURE);
	}
	rows = NULL;
	while (1)
	{
		row = parse_line(fd);
		if (!row)
			break ;
		ft_lstadd_back(&rows, ft_lstnew(row));
	}
	map = rows_to_map(rows);
	ft_lstclear(&rows, free_arri);
	return (map);
}
