/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 20:52:45 by abazzoun          #+#    #+#             */
/*   Updated: 2025/06/17 16:22:05 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	str_visible_len(const char *s, int precision)
{
	int	len;

	len = ft_strlen(s);
	if (precision != -1 && s == NULL)
		len = 0;
	else if (precision != -1 && precision < len)
		len = precision;
	return (len);
}

int	ft_printf_s(const char *s, t_flag *flag)
{
	int	len;

	if (s == NULL && flag->precision > -1 && flag->precision < 6)
		s = "";
	else if (s == NULL)
		s = "(null)";
	len = str_visible_len(s, flag->precision);
	if (len < flag->width)
	{
		if (flag->minus)
		{
			write(1, s, len);
			ft_printf_repeat_c(' ', flag->width - len);
		}
		else
		{
			ft_printf_repeat_c(' ', flag->width - len);
			write(1, s, len);
		}
		return (flag->width);
	}
	return (write(1, s, len));
}
