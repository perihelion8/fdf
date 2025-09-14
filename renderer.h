/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 12:11:14 by abazzoun          #+#    #+#             */
/*   Updated: 2025/09/14 13:22:01 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H

# include <stddef.h>

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

t_renderer	renderer_init(int width, int height);
void		renderer_render(t_renderer r);
void		renderer_put_pixel(t_renderer r, int x, int y, int color);

#endif
