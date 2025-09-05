/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:38:13 by abazzoun          #+#    #+#             */
/*   Updated: 2025/06/17 16:22:05 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_repeat_c(char c, int n)
{
	while (n-- > 0)
		write(1, &c, 1);
}

int	ft_printf_int_max(int a, int b)
{
	if (b > a)
		return (b);
	return (a);
}
