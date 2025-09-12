/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 14:03:08 by abazzoun          #+#    #+#             */
/*   Updated: 2025/09/12 23:09:36 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <math.h>

# include "get_next_line.h"
# include "libft.h"
# include "mlx.h"

typedef unsigned int	t_uint;

typedef struct s_arri
{
	int		*data;
	size_t	size;	
}	t_arri;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_map
{
	int		**cells;
	size_t	width;
	size_t	height;
}	t_map;

typedef struct s_draw_props
{
	int	offset_x;
	int	offset_y;
	int	scale;
}	t_draw_props;

typedef struct s_app
{
	void			*mlx;
	void			*win;
	t_map			*map;
	t_draw_props	props;
}	t_app;

void	*xmalloc(size_t	size);
void	free_arri(void *ptr);
void	free_map(t_map *map);
void	free_split(char **split);
bool	validator_file_name(char *file_name);
t_map	*parse_fdf(const char *file_name);
t_point	project_iso(int x, int y, int z, t_draw_props props);
void	draw_map(void *mlx, void *win, t_map *map, t_draw_props props);
int		handle_key(int keycode, void *param);
int		handle_close(void *param);

#endif
