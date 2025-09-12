/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 22:17:29 by abazzoun          #+#    #+#             */
/*   Updated: 2025/09/12 23:09:09 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_arri(void *ptr)
{
	t_arri	*arri;

	if (!ptr)
		return ;
	arri = ptr;
	if (arri->data)
		free(arri->data);
	free(arri);
}

void	free_map(t_map *map)
{
	size_t	i;

	if (!map)
		return ;
	if (map->width || map->height)
	{
		i = 0;
		while (i < map->height)
		{
			free(map->cells[i]);
			i++;
		}
		free(map->cells);
	}
	free(map);
}

void	free_split(char **split)
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
