/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 09:19:59 by abazzoun          #+#    #+#             */
/*   Updated: 2025/09/14 11:40:16 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_grid	*parse_fdf(const char *file_name)
{
	t_grid	*grid;
	t_list	*lines;
	int		fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	lines = list_create();	
	while (list_addback(lines, get_next_line(fd)) != -1)
		;
	close(fd);
	if (list_len(lines) < 1)
	{
		list_destroy(lines);
		exit(EXIT_FAILURE);
	}
	grid = grid_create(lines);
	list_destroy(lines);
	return (grid);
}
