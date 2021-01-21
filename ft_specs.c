/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproveme <eproveme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 13:16:59 by eproveme          #+#    #+#             */
/*   Updated: 2021/01/21 16:37:44 by eproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		none_spec(int n)
{
	if (n != 'c' && n != 's' && n != 'p' && n != 'd' && n != 'i' && n != 'u' &&
		n != 'x' && n != 'X' && n != '%')
		return (1);
	return (0);
}

int		ft_char(va_list arg, t_flag *flag, int i)
{
	int c;

	i = 0;
	c = va_arg(arg, int);
	num_flag(flag);
	if (flag->min)
		i += ft_putchar(c);
	while ((flag->num - 1) > 0)
	{
		if (flag->width || flag->min)
			i += ft_putchar(' ');
		else if (flag->zero)
			i += ft_putchar('0');
		flag->num--;
	}
	if (!flag->min)
		i += ft_putchar(c);
	return (i);
}

int		ft_pct(t_flag *flag, int i)
{
	i = 0;
	num_flag(flag);
	if (flag->min)
		i += ft_putchar('%');
	while ((flag->num - 1) > 0)
	{
		if (flag->width || flag->min)
			i += ft_putchar(' ');
		else if (flag->zero)
			i += ft_putchar('0');
		flag->num--;
	}
	if (!flag->min)
		i += ft_putchar('%');
	return (i);
}

int		ft_specs(va_list arg, const char **format, t_flag *flag, int i)
{
	i = 0;
	if (**format == '%')
		i += ft_pct(flag, i);
	else if (**format == 'c')
		i += ft_char(arg, flag, i);
	else if (**format == 'd' || **format == 'i')
		i += ft_d_i(arg, flag, i);
	else if (**format == 's')
		i += ft_str(arg, flag, i);
	else if (**format == 'u')
		i += ft_u(arg, flag, i);
	else if (**format == 'x')
		i += ft_x(arg, flag, i);
	else if (**format == 'X')
		i += ft_hex(arg, flag, i);
	else if (**format == 'p')
		i += ft_p(arg, flag, i);
	return (i);
}
