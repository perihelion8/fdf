/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 10:50:30 by abazzoun          #+#    #+#             */
/*   Updated: 2025/09/14 11:48:49 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_internal.h"

void	grid_print(t_grid *grid)
{
	size_t	i;
	size_t	j;
	t_cell	cell;

	i = 0;
	while (i < grid->height)
	{
		j = 0;
		while (j < grid->width)
		{
			cell = grid->cells[i][j];
			printf("%d ", cell.z);
			j++;
		}
		printf("\n");
		i++;
	}
}
