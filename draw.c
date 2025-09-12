/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 22:36:02 by abazzoun          #+#    #+#             */
/*   Updated: 2025/09/12 16:29:15 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	init_s_d(t_point p0, t_point p1, int *d, int *s)
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

static void	draw_line(void *mlx, void *win, t_point p0, t_point p1)
{
	int	d[2];
	int	s[2];
	int	err[2];

	init_s_d(p0, p1, d, s);
	err[0] = d[0] + d[1];
	while (1)
	{
		mlx_pixel_put(mlx, win, p0.x, p0.y, 0xFFFFFF);
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

void	draw_map(void *mlx, void *win, t_map *map, t_draw_props props)
{
	t_point	p[2];
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			p[0] = project_iso(j, i, map->cells[i][j], props);
			if (j + 1 < map->width)
			{
				p[1] = project_iso(j + 1, i, map->cells[i][j + 1], props);
				draw_line(mlx, win, p[0], p[1]);
			}
			if (i + 1 < map->height)
			{
				p[1] = project_iso(j, i + 1, map->cells[i + 1][j], props);
				draw_line(mlx, win, p[0], p[1]);
			}
			j++;
		}
		i++;
	}
}
