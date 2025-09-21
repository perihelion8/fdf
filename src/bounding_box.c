/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bounding_box.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 23:21:03 by abazzoun          #+#    #+#             */
/*   Updated: 2025/09/21 03:40:13 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "fdf.h"

static void	box_init(t_box *box)
{
	box->x_max = INT_MIN;
	box->x_min = INT_MAX;
	box->y_max = INT_MIN;
	box->y_min = INT_MAX;
	box->z_max = INT_MIN;
	box->z_min = INT_MAX;
}

static void	box_update_with_cell(t_box *box, t_point2d p, t_cell cell)
{
	if (cell.z > box->z_max)
		box->z_max = cell.z;
	if (cell.z < box->z_min)
		box->z_min = cell.z;
	if (p.x > box->x_max)
		box->x_max = p.x;
	if (p.x < box->x_min)
		box->x_min = p.x;
	if (p.y > box->y_max)
		box->y_max = p.y;
	if (p.y < box->y_min)
		box->y_min = p.y;
}

t_box	box_make(t_grid *grid, t_props *props)
{
	t_box		box;
	t_point2d	p;
	size_t		i;
	size_t		j;

	box_init(&box);
	i = 0;
	while (i < grid->height)
	{
		j = 0;
		while (j < grid->width)
		{
			p = project_iso(i, j, grid->cells[i][j], props);
			box_update_with_cell(&box, p, grid->cells[i][j]);
			j++;
		}
		i++;
	}
	return (box);
}
