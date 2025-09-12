/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 23:38:14 by abazzoun          #+#    #+#             */
/*   Updated: 2025/09/12 23:03:14 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_key(int keycode, void *param)
{
	t_app	*app;

	app = (t_app *)param;
	if (keycode == 65362)
		app->props.offset_y -= 10;
	else if (keycode == 65364)
		app->props.offset_y += 10;
	else if (keycode == 65361)
		app->props.offset_x -= 10;
	else if (keycode == 65363)
		app->props.offset_x += 10;
	else if (keycode == 61)
		app->props.scale += 1;
	else if (keycode == 45)
		app->props.scale -= 1;
	else if (keycode == 65307)
	{
		free_map(app->map);
		mlx_destroy_window(app->mlx, app->win);
		exit(0);
	}
	mlx_clear_window(app->mlx, app->win);
	draw_map(app->mlx, app->win, app->map, app->props);
	return (0);
}

int	handle_close(void *param)
{
	t_app	*app;

	app = param;
	free_map(app->map);
	mlx_destroy_window(app->mlx, app->win);
	exit(0);
	return (0);
}
