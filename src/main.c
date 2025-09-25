/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 22:37:44 by abazzoun          #+#    #+#             */
/*   Updated: 2025/09/25 09:51:34 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_props	props_make(t_grid *grid)
{
	t_props	props;
	t_box	box;
	float	scale[2];
	float	center[2];

	ft_memset(&props, 0, sizeof(t_props));
	props.scale = 1;
	props.scale_z = 1;
	box = box_make(grid, &props);
	props.z_max = box.z_max;
	props.z_min = box.z_min;
	scale[0] = SCREEN_W / (box.x_max - box.x_min);
	scale[1] = SCREEN_H / (box.y_max - box.y_min);
	if (scale[0] <= scale[1])
		props.scale = scale[0] * 0.9;
	else
		props.scale = scale[1] * 0.9;
	center[0] = (-1 *(box.x_max + box.x_min) / 2.0f);
	center[1] = (box.y_max + box.y_min) / 2.0f;
	props.offset_x = (int)((SCREEN_W / 2.0f) - center[0] * props.scale);
	props.offset_y = (int)((SCREEN_H / 2.0f) - center[1] * props.scale);
	props.center_x = grid->width / 2;
	props.center_y = grid->height / 2;
	props.redraw = 1;
	return (props);
}

int	main(int argc, char *argv[])
{
	t_renderer	r;
	t_grid		*grid;
	t_props		props;

	if (argc != 2)
		return (0);
	grid = parser_fdf_file(argv[1]);
	props = props_make(grid);
	r = renderer_create(SCREEN_W, SCREEN_H);
	renderer_run(&r, &props, grid);
	return (0);
}
