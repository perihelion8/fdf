/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 22:37:44 by abazzoun          #+#    #+#             */
/*   Updated: 2025/09/12 23:04:26 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_draw_props	draw_props_init(int width, int height)
{
	t_draw_props	props;

	props.scale = 10;
	props.offset_x = 400 - (width * props.scale) / 2;
	props.offset_y = 400 - (height * props.scale) / 2;
	return (props);
}

int	main(int argc, char *argv[])
{
	t_app	app;

	if (argc != 2)
		return (0);
	app.map = parse_fdf(argv[1]);
	app.props = draw_props_init(app.map->width, app.map->height);
	app.mlx = mlx_init();
	app.win = mlx_new_window(app.mlx, 800, 800, "fdf");
	draw_map(app.mlx, app.win, app.map, app.props);
	mlx_key_hook(app.win, handle_key, &app);
	mlx_hook(app.win, 17, 0, handle_close, &app);
	mlx_loop(app.mlx);
	return (0);
}
