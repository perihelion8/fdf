/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 14:03:08 by abazzoun          #+#    #+#             */
/*   Updated: 2025/09/14 13:29:29 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define FDF_HEIGHT 900
# define FDF_WIDTH 900

# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <math.h>

# include "get_next_line.h"
# include "list.h"
# include "libft.h"
# include "renderer.h"
# include "mlx.h"

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
}	t_point;

typedef struct s_point2d
{
	int	x;
	int	y;
	int	color;
}	t_point2d;

typedef struct s_props
{
	int		offset_x;
	int		offset_y;
	int		scale;
	double	rot_x;
	double	rot_y;
	double	rot_z;
}	t_props;

typedef struct s_fdf
{
	t_grid		*grid;
	t_props		props;
	t_renderer	r;
}	t_fdf;

void		*xmalloc(size_t	size);
t_grid		*parse_fdf(const char *file_name);
t_point2d	project_iso(int x, int y, t_cell cell, t_props props);
t_props		props_init();
void		draw_grid(t_renderer r, t_grid *grid, t_props props);
int			handle_key(int keycode, void *param);
int			handle_close(void *param);

#endif
