/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 22:28:22 by abazzoun          #+#    #+#             */
/*   Updated: 2025/09/20 18:49:28 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
