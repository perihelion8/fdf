/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 22:41:32 by abazzoun          #+#    #+#             */
/*   Updated: 2025/09/17 20:04:33 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	control_key(int keycode, t_props *props)
{
	if (keycode == 65362)
		props->offset_y -= 10;
	else if (keycode == 65364)
		props->offset_y += 10;
	else if (keycode == 65361)
		props->offset_x -= 10;
	else if (keycode == 65363)
		props->offset_x += 10;
	else if (keycode == 61)
		props->scale += 1;
	else if (keycode == 45)
		props->scale -= 1;
	else if (keycode == 'w')
		props->rot_x -= 0.05;
	else if (keycode == 's')
		props->rot_x += 0.05;
	else if (keycode == 'a')
		props->rot_y -= 0.05;
	else if (keycode == 'd')
		props->rot_y += 0.05;
	else if (keycode == 'q')
		props->rot_z -= 0.05;
	else if (keycode == 'e')
		props->rot_z += 0.05;
}

int	handle_key(int keycode, void *param)
{
	t_vars	*vars;
	t_img	img;

	vars = param;
	control_key(keycode, vars->props);
	if (keycode == 65307)
		handle_close(vars);
	img = vars->r->img;
	ft_memset(img.addr, 0, img.line_len * vars->r->height);
	draw_grid(vars->grid, vars->props, vars->r);
	renderer_push_img_to_win(vars->r);
	return (0);
}

int	handle_close(void *param)
{
	t_vars	*vars;

	vars = param;
	grid_destroy(vars->grid);
	renderer_destroy(vars->r);
	exit(0);
}
