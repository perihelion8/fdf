/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 15:48:04 by abazzoun          #+#    #+#             */
/*   Updated: 2025/09/17 11:17:35 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

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

void	*xmalloc(size_t	size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	return (ptr);
}
