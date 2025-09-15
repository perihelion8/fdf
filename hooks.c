/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */ /*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 23:38:14 by abazzoun          #+#    #+#             */
/*   Updated: 2025/09/14 21:07:28 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	clear_image(t_img *img, int height)
{
	ft_memset(img->addr, 0, img->line_len * height);
}

static void	handle_key_modify_prop(int keycode, t_fdf *fdf)
{
	if (keycode == 65362)
		fdf->props.offset_y -= 10;
	else if (keycode == 65364)
		fdf->props.offset_y += 10;
	else if (keycode == 65361)
		fdf->props.offset_x -= 10;
	else if (keycode == 65363)
		fdf->props.offset_x += 10;
	else if (keycode == 61)
		fdf->props.scale += 1;
	else if (keycode == 45)
		fdf->props.scale -= 1;
	else if (keycode == 'w')
		fdf->props.rot_x -= 0.05;
	else if (keycode == 's')
		fdf->props.rot_x += 0.05;
	else if (keycode == 'a')
		fdf->props.rot_y -= 0.05;
	else if (keycode == 'd')
		fdf->props.rot_y += 0.05;
	else if (keycode == 'q')
		fdf->props.rot_z -= 0.05;
	else if (keycode == 'e')
		fdf->props.rot_z += 0.05;
}

int	handle_key(int keycode, void *param)
{
	t_fdf *fdf;

	fdf = param;
	handle_key_modify_prop(keycode, fdf);
	if (keycode == 'r')
		fdf->props = props_init();
	else if (keycode == 65307)
		handle_close(fdf);
	clear_image(&fdf->r.img, fdf->r.height);
	draw_grid(&fdf->r, fdf->grid, fdf->props);
	renderer_push_img_to_win(&fdf->r);
	return (0);
}

int	handle_close(void *param)
{
	t_fdf	*fdf;

	fdf = param;
	grid_destroy(fdf->grid);
	mlx_destroy_window(fdf->r.mlx, fdf->r.win);
	exit(0);
	return (0);
}
