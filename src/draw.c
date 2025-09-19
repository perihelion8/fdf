/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 22:36:02 by abazzoun          #+#    #+#             */
/*   Updated: 2025/09/19 12:07:26 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_grid(t_grid *grid, t_props *props, t_renderer *r)
{
	t_point2d	p[2];
	size_t		i;
	size_t		j;

	i = 0;
	while (i < grid->height)
	{
		j = 0;
		while (j < grid->width)
		{
			p[0] = project_iso(j, i, grid->cells[i][j], props);
			if (j + 1 < grid->width)
			{
				p[1] = project_iso(j + 1, i, grid->cells[i][j + 1], props);
				line_bresenham(p[0], p[1], r);
			}
			if (i + 1 < grid->height)
			{
				p[1] = project_iso(j, i + 1, grid->cells[i + 1][j], props);
				line_bresenham(p[0], p[1], r);
			}
			j++;
		}
		i++;
	}
}
