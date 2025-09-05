/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric_projection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 10:47:12 by abazzoun          #+#    #+#             */
/*   Updated: 2025/09/05 10:48:00 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"

static double	**alllocate_points(t_list *rows)
{
	double	**points;
	t_list	*rowsp;
	size_t	total_points;

	rowsp = rows;
	total_points = 0;
	while (rowsp)
	{
		total_points += rowsp->size;
		rowsp = rowsp->next;
	}
	points = xmalloc(2 * sizeof(*points));
	points[0] = xmalloc(total_points * sizeof(**points));
	points[1] = xmalloc(total_points * sizeof(**points));
	return (points);
}

double	**isometric_projection(t_list *rows, int angle_rad)
{
	double	**points;
	t_list	*rowsp;
	t_uint	i;
	t_uint	j;
	t_uint	k;

	points = allocate_points(rows);
	rowsp = rows;
	k = 0;
	i = 0;
	while (rowsp)
	{
		j = 0;
		while (j < rowsp->size)
		{
			points[0][k] = (j - i) * cos(angle_rad);
			points[1][k] = (j + i) * sin(angle_rad) - rowsp->data[j];
			j++;
			k++;
		}
		i++;
		rowsp = rowsp->next;
	}
	return (points);
}
