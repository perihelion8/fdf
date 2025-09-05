/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:58:42 by abazzoun          #+#    #+#             */
/*   Updated: 2025/06/17 16:34:05 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const t_byte	*srcb;
	t_byte			*dstb;

	srcb = (const t_byte *) src;
	dstb = (t_byte *) dst;
	while (n--)
		*dstb++ = *srcb++;
	return (dst);
}
