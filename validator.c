/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 02:32:59 by abazzoun          #+#    #+#             */
/*   Updated: 2025/09/04 02:40:31 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_bool	validator_file_name(char *file_name)
{
	t_uint	i;

	i = 0;
	while (file_name[i])
	{
		if (file_name[i] == ' ')
			return (0);
		i++;
	}
	if (i < 6)
		return (0);
	if (ft_strcmp(file_name + (i - 4), ".fdf") != 0)
		return (0);
	return (1);
}
