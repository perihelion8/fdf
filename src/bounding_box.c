/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bounding_box.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 23:21:03 by abazzoun          #+#    #+#             */
/*   Updated: 2025/09/25 22:44:32 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	box_init(t_box *box, int x0, int y0, t_cell cell0)
{
	box->x_max = x0;
	box->x_min = x0;
	box->y_max = y0;
	box->y_min = y0;
	box->z_max = cell0.z;
	box->z_min = cell0.z;
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

	p = project_iso(0, 0, grid->cells[0][0], props);
	box_init(&box, p.x, p.y, grid->cells[0][0]);
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
