/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project_iso.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 10:47:12 by abazzoun          #+#    #+#             */
/*   Updated: 2025/09/14 15:42:47 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_point	rotate_point(int x, int y, int z, t_props props)
{
	t_point	p;
	t_point	tmp;

	p.x = x;
	p.y = y;
	p.z = z;
	tmp.y = p.y * cos(props.rot_x) - p.z * sin(props.rot_x);
	tmp.z = p.y * sin(props.rot_x) + p.z * cos(props.rot_x);
	tmp.x = p.x;
	p = tmp;
	tmp.x =	p.x * cos(props.rot_y) + p.z * sin(props.rot_y);
	tmp.z = -p.x * sin(props.rot_y) + p.z * cos(props.rot_y);
	tmp.y = y;
	p = tmp;
	tmp.x = p.x * cos(props.rot_z) - p.y * sin(props.rot_z);
	tmp.y = p.x * sin(props.rot_z) + p.y * cos(props.rot_z);
	tmp.z = p.z;
	return (tmp);
}

t_point2d	project_iso(int x, int y, t_cell cell, t_props props)
{
	t_point		p;
	t_point2d	proj;
	double		angle;

	p.x = x * props.scale;
	p.y = y * props.scale;
	p.z = cell.z * props.scale * 0.3;
	p = rotate_point(p.x, p.y, p.z, props);
	angle = M_PI / 6;
	proj.x = (int)((p.x - p.y) * cos(angle)) + props.offset_x;
	proj.y = (int)((p.x + p.y) * sin(angle) - p.z) + props.offset_y;
	proj.color = cell.color;
	return (proj);
}
