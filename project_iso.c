/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project_iso.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 10:47:12 by abazzoun          #+#    #+#             */
/*   Updated: 2025/09/12 22:13:19 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	project_iso(int x, int y, int z, t_draw_props props)
{
	t_point	p;
	double	angle;

	x = x * props.scale;
	y = y * props.scale;
	z = z * props.scale * 0.1;
	angle = M_PI / 6;
	p.x = (int)((x - y) * cos(angle)) + props.offset_x;
	p.y = (int)((x + y) * sin(angle) - z) + props.offset_y;
	return (p);
}
