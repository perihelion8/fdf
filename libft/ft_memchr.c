/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 21:32:26 by a                 #+#    #+#             */
/*   Updated: 2025/06/17 16:33:53 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *m, int c, size_t n)
{
	const t_byte	*mb;
	size_t			i;

	mb = (const t_byte *) m;
	i = 0;
	while (i < n)
	{
		if (mb[i] == (t_byte) c)
			return ((void *)(mb + i));
		i++;
	}
	return (NULL);
}
