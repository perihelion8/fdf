/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 12:16:56 by abazzoun          #+#    #+#             */
/*   Updated: 2025/09/17 22:52:24 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"

t_renderer	renderer_create(int width, int height)
{
	t_renderer	r;
	t_img		i;

	r.height = height;
	r.width = width;
	r.mlx = mlx_init();
	r.win = mlx_new_window(r.mlx, width, height, "fdf");
	i.img = mlx_new_image(r.mlx, width, height);
	i.addr = mlx_get_data_addr(i.img, &i.bpp, &i.line_len, &i.pixel_order);
	r.img = i;
	return (r);
}

void	renderer_run(t_renderer *r, void *var, t_hook_k k, t_hook_c c)
{
	renderer_push_img_to_win(r);
	mlx_key_hook(r->win, k, var);
	mlx_hook(r->win, 17, 0, c, var);
	mlx_loop(r->mlx);
}

void	renderer_put_pixel(t_renderer *r, int x, int y, int color)
{
	t_img	img;
	char	*dst;

	if (x < 0 || x >= r->width || y < 0 || y >= r->height)
		return ;
	img = r->img;
	dst = img.addr + (y * img.line_len + x * (img.bpp / 8));
	*(unsigned int *)dst = color;
}

void	renderer_push_img_to_win(t_renderer *r)
{
	mlx_put_image_to_window(r->mlx, r->win, r->img.img, 0, 0);
}

void	renderer_destroy(t_renderer *r)
{
	mlx_destroy_image(r->mlx, r->img.img);
	mlx_destroy_window(r->mlx, r->win);
	mlx_destroy_display(r->mlx);
	free(r->mlx);
}
