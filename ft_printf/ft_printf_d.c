/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 22:27:22 by abazzoun          #+#    #+#             */
/*   Updated: 2025/06/17 16:22:05 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	digits_count(long n)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	if (n < 0)
		n = -n;
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
	if (n < 0 || (n >= 0 && (flag->plus || flag->space)))
		prop->core_len = prop->prec_len + 1;
	else
		prop->core_len = prop->prec_len;
	prop->total_len = ft_printf_int_max(prop->core_len, flag->width);
	if (flag->precision != -1)
		prop->width_char = ' ';
	else if (flag->zero)
		prop->width_char = '0';
	else
		prop->width_char = ' ';
}

static void	ft_putnbrl(long n)
{
	if (n < 0)
	{
		n = -1 * n;
		write(1, "-", 1);
	}
	if (n >= 10)
		ft_putnbrl(n / 10);
	ft_putchar_fd('0' + n % 10, 1);
}

static int	print_core(long n, t_numprop *prop, t_flag *flag)
{
	if (flag->precision == 0 && n == 0)
		return (0);
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	else if (flag->plus)
		write(1, "+", 1);
	else if (flag->space)
		write(1, " ", 1);
	ft_printf_repeat_c('0', prop->prec_len - prop->digit_len);
	ft_putnbrl(n);
	return (prop->core_len);
}

int	ft_printf_d(int n, t_flag *flag)
{
	t_numprop	prop;
	long		num;

	num = (long)n;
	init_num_prop(n, &prop, flag);
	if (prop.total_len > prop.core_len)
	{
		if (flag->minus)
		{
			print_core(num, &prop, flag);
			ft_printf_repeat_c(prop.width_char, prop.total_len - prop.core_len);
		}
		else
		{
			if (prop.width_char == '0' && num < 0)
			{
				write(1, "-", 1);
				num = -num;
			}
			ft_printf_repeat_c(prop.width_char, prop.total_len - prop.core_len);
			print_core(num, &prop, flag);
		}
		return (prop.total_len);
	}
	return (print_core(num, &prop, flag));
}
