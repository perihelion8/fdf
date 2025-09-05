/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 14:03:08 by abazzoun          #+#    #+#             */
/*   Updated: 2025/09/05 10:48:24 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

typedef struct s_arri
{
	int		*data;
	size_t	size;	
}	t_arri;

t_list	*parse_fdf(const char *file_name);
double	**isometric_projection(t_list *rows, int angle_rad);

#endif
