/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 20:45:00 by abazzoun          #+#    #+#             */
/*   Updated: 2025/06/17 16:22:05 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_c(char c, t_flag *flag)
{
	if (flag->width > 1)
	{
		if (flag->minus)
		{
			write(1, &c, 1);
			ft_printf_repeat_c(' ', flag->width - 1);
		}
		else
		{
			ft_printf_repeat_c(' ', flag->width - 1);
			write(1, &c, 1);
		}
		return (flag->width);
	}
	return (write(1, &c, 1));
}
