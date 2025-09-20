/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 15:48:04 by abazzoun          #+#    #+#             */
/*   Updated: 2025/09/20 22:35:11 by abazzoun         ###   ########.fr       */
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
	return (-1);
}

int	hextoi(const char *str)
{
	int	n;
	int	digit;

	n = 0;
	str += 2;
	while (*str)
	{
		digit = index_hexbase(*str);
		if (digit == -1)
			break ;
		n = n * 16 + digit;
		str++;
	}
	return (n);
}

int	try_free(void *ptr)
{
	if (!ptr)
		return (0);
	free(ptr);
	return (1);
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
