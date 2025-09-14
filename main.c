/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 22:37:44 by abazzoun          #+#    #+#             */
/*   Updated: 2025/09/14 13:29:33 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_props	props_init(void)
{
	t_props	props;

	props.scale = 10;
	props.rot_x = 0;
	props.rot_y = 0;
	props.rot_z = 0;
	props.offset_x = 0;
	props.offset_y = 0;
	return (props);
}

int	main(int argc, char *argv[])
{
	t_fdf	fdf;

	if (argc != 2)
		return (0);
	fdf.grid = parse_fdf(argv[1]);
	fdf.props = props_init();
	fdf.r = renderer_init(FDF_WIDTH, FDF_HEIGHT);
	mlx_key_hook(fdf.r.win, handle_key, &fdf);
	mlx_hook(fdf.r.win, 17, 0, handle_close, &fdf);
	mlx_loop(fdf.r.mlx);
	return (0);
}
