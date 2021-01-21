/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproveme <eproveme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 13:35:36 by eproveme          #+#    #+#             */
/*   Updated: 2021/01/21 16:38:33 by eproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		x_count(unsigned int n)
{
	int	i;

	i = 1;
	if (n != 0)
	{
		while (n >= 16)
		{
			n = n / 16;
			i++;
		}
	}
	return (i);
}

int		ft_x_dot(t_flag *flag, int i, unsigned int x)
{
	i = 0;
	num_flag(flag);
	dot_flag(flag, 'i');
	if (flag->prec == -1 && x == 0)
		flag->num++;
	if (!flag->min)
		i += ft_putsmth(flag->num, flag->dot, i, ' ');
	i += ft_putsmth(flag->prec, flag->len, i, '0');
	if (flag->prec != -1 || x != 0)
		i += ft_puthex(x, 'x');
	if (flag->min)
		i += ft_putsmth(flag->num, flag->dot, i, ' ');
	return (i);
}

int		ft_x_solo(t_flag *flag, int i, unsigned int x)
{
	i = 0;
	num_flag(flag);
	if (flag->prec == -1 && x == 0)
		flag->num++;
	if (flag->min && (flag->prec != -1 || x != 0))
		i += ft_puthex(x, 'x');
	if (flag->width || flag->min)
		i += ft_putsmth(flag->num, flag->len, i, ' ');
	else if (flag->zero || flag->prec)
		i += ft_putsmth(flag->num, flag->len, i, '0');
	if (!flag->min && (flag->prec != -1 || x != 0))
		i += ft_puthex(x, 'x');
	return (i);
}

int		ft_x(va_list arg, t_flag *flag, int i)
{
	unsigned int x;

	x = va_arg(arg, unsigned int);
	flag->len = x_count(x);
	if (flag->prec && (flag->width || flag->zero || flag->min))
		i += ft_x_dot(flag, i, x);
	else if (flag->width || flag->min || flag->zero || flag->prec)
		i += ft_x_solo(flag, i, x);
	else
		i += ft_puthex(x, 'x');
	return (i);
}
