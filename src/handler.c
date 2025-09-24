/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 22:41:32 by abazzoun          #+#    #+#             */
/*   Updated: 2025/09/25 02:37:26 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_key(int keycode, void *param)
{
	t_props	*props;
	t_vars	*vars;

	vars = ((t_vars *)param);
	props = vars->props;
	if (keycode == 65307)
		handle_close(param);
	else if (keycode == 'z' && props->scale_z < 1)
		props->scale_z += 0.1;
	else if (keycode == 'x' && props->scale_z > -1)
		props->scale_z -= 0.1;
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
	return (0);
}

int	mouse_press(int button, int x, int y, t_props *props)
{
	if (button == MOUSE_LEFT || button == MOUSE_RIGHT)
	{
		props->mouse_button = button;
		props->last_mouse_x = x;
		props->last_mouse_y = y;
	}
	return (0);
}

int	mouse_release(int button, int x, int y, t_props *props)
{
	(void)x;
	(void)y;
	(void)button;		
	props->mouse_button = 0;
	return (0);
}

int	mouse_move(int x, int y, t_props *props)
{
	int		dx;
	int		dy;

	if (props->mouse_button == 0)
		return (0);
	dx = x - props->last_mouse_x;
	dy = y - props->last_mouse_y;
	if (props->mouse_button == MOUSE_LEFT)
	{
		props->rot_y += dx * 0.01f;
		props->rot_x += dy * 0.01f;
	}
	else if (props->mouse_button == MOUSE_RIGHT)
		props->rot_z += dx * 0.01f;
	props->last_mouse_x = x;
	props->last_mouse_y = y;
	return (0);
}

int	handle_close(void *param)
{
	t_vars	*vars;

	vars = param;
	grid_destroy(vars->grid);
	renderer_destroy(vars->r);
	exit(EXIT_SUCCESS);
}
