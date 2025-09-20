/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 14:03:08 by abazzoun          #+#    #+#             */
/*   Updated: 2025/09/21 02:22:39 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define SCREEN_W 1024
# define SCREEN_H 768

# include <fcntl.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <math.h>

# include "libft.h"
# include "get_next_line.h"
# include "utils.h"
# include "list.h"
# include "renderer.h"

typedef struct s_bresenham
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	e;
	int	e2;
}	t_bresenham;

typedef struct s_cell
{
	int	z;
	int	color;
}	t_cell;

typedef struct s_grid
{
	t_cell	**cells;
	size_t	width;
	size_t	height;
}	t_grid;

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
}	t_point;

typedef struct s_point2d
{
	int	x;
	int	y;
	int	color;
}	t_point2d;

typedef struct s_box
{
	int	x_max;
	int	x_min;
	int	y_max;
	int	y_min;
	int	z_max;
	int	z_min;
}	t_box;

typedef struct s_props
{
	int		offset_x;
	int		offset_y;
	float	scale;
	float	scale_z;
	float	rot_x;
	float	rot_y;
	float	rot_z;
}	t_props;

typedef struct s_vars
{
	t_grid		*grid;
	t_props		*props;
	t_renderer	*r;
}	t_vars;

char		**split_and_free_src(char *s, char c);
size_t		split_len(char **split);
void		split_free(char **split);
void		grid_destroy(t_grid *grid);
t_grid		*parser_fdf_file(const char *file_name);
t_point2d	project_iso(int x, int y, t_cell cell, t_props *props);
void		line_bresenham(t_point2d p0, t_point2d p1, t_renderer *r);
void		draw_grid(t_grid *grid, t_props *props, t_renderer *r);
t_box		box_make(t_grid *grid, t_props *props);
int			handle_key(int keycode, void *param);
int			handle_close(void *param);
t_point2d	bounding_box(t_grid *grid, t_props *props);

#endif
