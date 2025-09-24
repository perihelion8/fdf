/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 02:06:10 by abazzoun          #+#    #+#             */
/*   Updated: 2025/09/25 02:17:28 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	update(void *param)
{
	t_vars	*vars;

	vars = param;
	draw_grid(vars->grid, vars->props, vars->r);
	renderer_push_img_to_win(param);
	return (0);
}
