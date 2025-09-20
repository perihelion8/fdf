/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 22:37:44 by abazzoun          #+#    #+#             */
/*   Updated: 2025/09/21 02:30:23 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_props	props_make(t_grid *grid)
{
	t_props		props;
	t_box		box;
	float		scale[2];
	float		center[2];

	ft_memset(&props, 0, sizeof(t_props));
	props.scale = 1;
	props.scale_z = 1;
	box = box_make(grid, &props);
	scale[0] = SCREEN_W / (box.x_max - box.x_min);
	scale[1] = SCREEN_H / (box.y_max - box.y_min);
	if (scale[0] <= scale[1])
		props.scale = scale[0] * 0.9;
	else
		props.scale = scale[1] * 0.9;
	box = box_make(grid, &props);
	center[0] = (box.x_max + box.x_min) / 2.0f;
	center[1] = (box.y_max + box.y_min) / 2.0f;
	props.offset_x = (int)roundf((SCREEN_W / 2.0f) - center[0]);
	props.offset_y = (int)roundf((SCREEN_H / 2.0f) - center[1]);
	return (props);
}

static t_vars	vars_make(t_grid *grid, t_props *props, t_renderer *r)
{
	t_vars	vars;

	vars.grid = grid;
	vars.props = props;
	vars.r = r;
	return (vars);
}

int	main(int argc, char *argv[])
{
	t_renderer	r;
	t_grid		*grid;
	t_props		props;
	t_vars		vars;

	if (argc != 2)
		return (0);
	grid = parser_fdf_file(argv[1]);
	props = props_make(grid);
	r = renderer_create(SCREEN_W, SCREEN_H);
	draw_grid(grid, &props, &r);
	vars = vars_make(grid, &props, &r);
	renderer_run(&r, &vars, handle_key, handle_close);
	return (0);
}
