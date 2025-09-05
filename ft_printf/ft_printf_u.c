/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:24:50 by abazzoun          #+#    #+#             */
/*   Updated: 2025/06/17 16:27:46 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	digits_count(t_uint n)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	while (n > 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

static void	init_num_prop(int n, t_numprop *prop, t_flag *flag)
{
	prop->digit_len = digits_count(n);
	if (n == 0 && flag->precision == 0)
		prop->digit_len = 0;
	prop->prec_len = ft_printf_int_max(prop->digit_len, flag->precision);
	prop->total_len = ft_printf_int_max(prop->prec_len, flag->width);
	if (flag->precision != -1)
		prop->width_char = ' ';
	else if (flag->zero)
		prop->width_char = '0';
	else
		prop->width_char = ' ';
}

static void	putnbru(t_uint n)
{
	if (n >= 10)
		putnbru(n / 10);
	ft_putchar_fd('0' + n % 10, 1);
}

static int	print_core(t_uint n, t_numprop *prop, t_flag *flag)
{
	if (flag->precision == 0 && n == 0)
		return (0);
	ft_printf_repeat_c('0', prop->prec_len - prop->digit_len);
	putnbru(n);
	return (prop->prec_len);
}

int	ft_printf_u(t_uint n, t_flag *flag)
{
	t_numprop	prop;

	init_num_prop(n, &prop, flag);
	if (prop.total_len > prop.prec_len)
	{
		if (flag->minus)
		{
			print_core(n, &prop, flag);
			ft_printf_repeat_c(' ', prop.total_len - prop.prec_len);
		}
		else
		{
			ft_printf_repeat_c(prop.width_char, prop.total_len - prop.prec_len);
			print_core(n, &prop, flag);
		}
		return (flag->width);
	}
	return (print_core(n, &prop, flag));
}
