/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_bresenham.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 12:04:24 by abazzoun          #+#    #+#             */
/*   Updated: 2025/09/19 12:35:38 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_bresenham	props_init(t_point2d p0, t_point2d p1)
{
	t_bresenham	props;

	props.dx = abs(p1.x - p0.x);
	props.dy = -abs(p1.y - p0.y);
	if (p0.x < p1.x)
		props.sx = 1;
	else
		props.sx = -1;
	if (p0.y < p1.y)
		props.sy = 1;
	else
		props.sy = -1;
	props.e = props.dx + props.dy;
	return (props);
}

void	line_bresenham(t_point2d p0, t_point2d p1, t_renderer *r)
{
	t_bresenham	props;

	props = props_init(p0, p1);
	while (1)
	{
		renderer_put_pixel(r, p0.x, p0.y, p1.color);
		if (p0.x == p1.x && p0.y == p1.y)
			break ;
		props.e2 = 2 * props.e;
		if (props.e2 >= props.dy)
		{
			props.e += props.dy;
			p0.x += props.sx;
		}
		if (props.e2 <= props.dx)
		{
			props.e += props.dx;
			p0.y += props.sy;
		}
	}
}
