/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:01:44 by abazzoun          #+#    #+#             */
/*   Updated: 2025/06/17 16:29:04 by abazzoun         ###   ########.fr       */
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
		n /= 16;
	}
	return (count);
}

static void	init_num_prop(int n, t_byte upper_x, t_numprop *prop, t_flag *flag)
{
	prop->digit_len = digits_count(n);
	if (n == 0 && flag->precision == 0)
		prop->digit_len = 0;
	prop->prec_len = ft_printf_int_max(prop->digit_len, flag->precision);
	prop->core_len = prop->prec_len;
	prop->total_len = ft_printf_int_max(prop->prec_len, flag->width);
	prop->upper_x = upper_x;
	if (flag->precision != -1)
		prop->width_char = ' ';
	else if (flag->zero)
		prop->width_char = '0';
	else if (flag->width)
		prop->width_char = ' ';
}

static void	puthex(t_uint n, char *hex)
{
	if (n >= 16)
		puthex(n / 16, hex);
	ft_putchar_fd(hex[n % 16], 1);
}

static int	print_core(t_uint n, t_numprop *prop, t_flag *flag)
{
	char	*hex;
	int		prefix_len;

	prefix_len = 0;
	if (n == 0 && flag->precision == 0)
		return (0);
	if (flag->hash && prop->upper_x && n > 0)
		prefix_len += write(1, "0X", 2);
	else if (flag->hash && n > 0)
		prefix_len += write(1, "0x", 2);
	ft_printf_repeat_c('0', prop->prec_len - prop->digit_len);
	if (prop->upper_x)
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	puthex(n, hex);
	return (prop->core_len + prefix_len);
}

int	ft_printf_x(t_uint n, t_byte upper_x, t_flag *flag)
{
	t_numprop	prop;

	init_num_prop(n, upper_x, &prop, flag);
	if (prop.core_len < prop.total_len)
	{
		if (flag->minus)
		{
			print_core(n, &prop, flag);
			ft_printf_repeat_c(' ', prop.total_len - prop.core_len);
		}
		else
		{
			ft_printf_repeat_c(prop.width_char, prop.total_len - prop.core_len);
			print_core(n, &prop, flag);
		}
		return (prop.total_len);
	}
	return (print_core(n, &prop, flag));
}
