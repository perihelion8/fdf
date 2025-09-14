/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 09:47:03 by abazzoun          #+#    #+#             */
/*   Updated: 2025/09/14 11:31:37 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_internal.h"
#include "libft.h"

static int	index_hexbase(char c)
{
	const char	*base_upper;
	const char	*base_lower;
	int			i;

	base_lower = "0123456789abcdef";
	base_upper = "0123456789ABCDEF";
	i = 0;
	while (i < 16)
	{
		if (c == base_lower[i])
			return (i);
		if (c == base_upper[i])
			return (i);
		i++;
	}
	return (i);
}

int	hextoi(const char *str)
{
	int	n;

	n = 0;
	str += 2;
	while (*str)
	{
		n = n * 16 + index_hexbase(*str);
		str++;
	}
	return (n);
}

void	free_split(char **split)
{
	size_t	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
