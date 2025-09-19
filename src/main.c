/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 22:37:44 by abazzoun          #+#    #+#             */
/*   Updated: 2025/09/19 03:47:41 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_props	props_init(void)
{
	t_props		props;

	props.scale = 10;
	props.scale_z = 0.1;
	props.rot_x = 0;
	props.rot_y = 0;
	props.rot_z = 0;
	props.offset_x = FDF_WIDTH / 2;
	props.offset_y = FDF_HEIGHT / 2;
	return (props);
}

static t_vars	vars_init(t_grid *grid, t_props *props, t_renderer *r)
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
	grid = parse_fdf(argv[1]);
	props = props_init();
	r = renderer_create(FDF_WIDTH, FDF_HEIGHT);
	draw_grid(grid, &props, &r);
	vars = vars_init(grid, &props, &r);
	renderer_run(&r, &vars, handle_key, handle_close);
	return (0);
}
