/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 22:37:44 by abazzoun          #+#    #+#             */
/*   Updated: 2025/09/05 10:47:50 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "fdf.h"


int	main(int argc, char *argv[])
{
	t_list	*map;

	if (argc != 2)
		return (0);
	if (validate_file_name(argv[1]))
		return (0);
	map = parse_fdf(argv[1]);
	if (!map || ft_lstsize(map) < 1)
		return (0);
	
	
}
