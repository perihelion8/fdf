/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 12:19:19 by abazzoun          #+#    #+#             */
/*   Updated: 2025/09/04 12:50:42 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_internal.h"

char	*get_next_line(int fd)
{
	static char	*repo;
	char		buffer[BUFFER_SIZE + 1];
	int			nread;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (ft_gnl_char_index(repo, '\n') == -1)
	{
		nread = read(fd, buffer, BUFFER_SIZE);
		if (nread <= 0)
			break ;
		buffer[nread] = '\0';
		repo = ft_gnl_str_append(repo, buffer);
		if (repo == NULL)
			return (NULL);
	}
	if (repo == NULL)
		return (NULL);
	if (*repo == '\0')
	{
		free(repo);
		repo = NULL;
		return (NULL);
	}
	return (ft_gnl_line_pop(&repo));
}
