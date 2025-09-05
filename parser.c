/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 21:32:27 by abazzoun          #+#    #+#             */
/*   Updated: 2025/09/04 18:33:02 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static t_arri	parse_line(int	fd)
{
	t_arri	*row;
	char	*line;
	size_t	i;

	line = get_next_line(fd);
	if (!line)
		return (NULL);
	split = ft_split(line);
	if (!split)
		libft_err();
	i = 0;
	while (split[i])
		i++;
	row = xmalloc(sizeof(*row));
	row->size = i;
	row->data = xmalloc(sizeof(int) * row->size);
	i = 0;
	while (split[i])
	{
		row->data[i] = ft_atoi(split[i]);
		i++;
	}
	return (row);
}

t_list	*parse_fdf(const char *file_name)
{
	t_list	*rows;
	t_arri	*row;
	int		fd;

	fd = open(file_name);
	if (!fd)
	{
		perror();
		exit();
	}
	rows = NULL;
	while (1)
	{
		row = parse_line(fd);
		if (!row)
			break ;
		ft_lst_addback(rows);
	}
	return (rows);
}
