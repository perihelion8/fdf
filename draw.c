/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 22:36:02 by abazzoun          #+#    #+#             */
/*   Updated: 2025/09/14 13:06:29 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	init_s_d(t_point2d p0, t_point2d p1, int *d, int *s)
{
	d[0] = abs(p1.x - p0.x);
	d[1] = -abs(p1.y - p0.y);
	if (p0.x < p1.x)
		s[0] = 1;
	else
		s[0] = -1;
	if (p0.y < p1.y)
		s[1] = 1;
	else
		s[1] = -1;
}

static void	draw_line(t_renderer r, t_point2d p0, t_point2d p1)
{
	int	d[2];
	int	s[2];
	int	err[2];

	init_s_d(p0, p1, d, s);
	err[0] = d[0] + d[1];
	while (1)
	{
		renderer_put_pixel(r, p0.x, p0.y, p1.color);
		if (p0.x == p1.x && p0.y == p1.y)
			break ;
		err[1] = 2 * err[0];
		if (err[1] >= d[1])
		{
			err[0] += d[1];
			p0.x += s[0];
		}
		if (err[1] <= d[0])
		{
			err[0] += d[0];
			p0.y += s[1];
		}
	}
}

void	draw_grid(t_renderer r, t_grid *grid, t_props props)
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
				draw_line(r, p[0], p[1]);
			}
			if (i + 1 < grid->height)
			{
				p[1] = project_iso(j, i + 1, grid->cells[i + 1][j], props);
				draw_line(r, p[0], p[1]);
			}
			j++;
		}
		i++;
	}
}
