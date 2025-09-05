/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:13:54 by abazzoun          #+#    #+#             */
/*   Updated: 2025/06/17 16:34:08 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	const t_byte	*srcb;
	t_byte			*dstb;

	srcb = (const t_byte *) src;
	dstb = (t_byte *) dst;
	if (dstb > srcb)
	{
		dstb += n - 1;
		srcb += n - 1;
		while (n--)
			*dstb-- = *srcb--;
	}
	else
		while (n--)
			*dstb++ = *srcb++;
	return (dst);
}
