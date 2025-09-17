/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 12:11:14 by abazzoun          #+#    #+#             */
/*   Updated: 2025/09/17 19:38:55 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H

# include "mlx.h"

typedef int	(*t_hook_k)(int keycode, void * p);
typedef int	(*t_hook_c)(void *);

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		pixel_order;
}	t_img;

typedef struct s_renderer
{
	void	*mlx;
	void	*win;
	t_img	img;
	int		width;
	int		height;
}	t_renderer;

t_renderer	renderer_create(int width, int height);
void		renderer_destroy(t_renderer *r);
void		renderer_run(t_renderer *r, void *var, t_hook_k k, t_hook_c c);
void		renderer_put_pixel(t_renderer *r, int x, int y, int color);
void		renderer_push_img_to_win(t_renderer *r);

#endif
