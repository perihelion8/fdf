/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 14:03:08 by abazzoun          #+#    #+#             */
/*   Updated: 2025/09/17 23:44:30 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define FDF_HEIGHT 900
# define FDF_WIDTH 900

# include <fcntl.h>
# include <stdbool.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <math.h>
# include <limits.h>

# include "libft.h"
# include "get_next_line/get_next_line.h"
# include "utils.h"
# include "list.h"
# include "renderer.h"

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
	double	scale_z;
	double	rot_x;
	double	rot_y;
	double	rot_z;
}	t_props;

typedef struct s_vars
{
	t_grid		*grid;
	t_props		*props;
	t_renderer	*r;
}	t_vars;

t_grid		*lines_to_grid(t_list *lines);
void		grid_destroy(t_grid *grid);
t_grid		*parse_fdf(const char *file_name);
t_point2d	project_iso(int x, int y, t_cell cell, t_props *props);
void		draw_grid(t_grid *grid, t_props *props, t_renderer *r);
int			handle_key(int keycode, void *param);
int			handle_close(void *param);
t_point2d	bounding_box(t_grid *grid, t_props *props);

#endif
