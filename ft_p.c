/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproveme <eproveme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 13:32:25 by eproveme          #+#    #+#             */
/*   Updated: 2021/01/21 16:36:52 by eproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		p_count(unsigned long long int n)
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

int		ft_p_dot(t_flag *flag, int i, unsigned long long int p)
{
	i = 0;
	num_flag(flag);
	dot_flag(flag, 'i');
	if (!p)
		flag->num++;
	if (!flag->min)
		i += ft_putsmth(flag->num, (flag->len + 2), i, ' ');
	i += ft_putstr("0x");
	i += ft_putsmth(flag->prec, flag->len, i, '0');
	if (p || flag->prec > 0)
		i += ft_puthex(p, 'x');
	if (flag->min)
		i += ft_putsmth(flag->num, (flag->len + 2), i, ' ');
	return (i);
}

int		ft_p_solo(t_flag *flag, int i, unsigned long long int p)
{
	i = 0;
	num_flag(flag);
	if (flag->min)
	{
		i += ft_putstr("0x");
		i += ft_puthex(p, 'x');
	}
	if (flag->width || flag->min)
		i += ft_putsmth(flag->num, (flag->len + 2), i, ' ');
	else if (flag->zero || flag->prec)
	{
		i += ft_putstr("0x");
		i += ft_putsmth(flag->num, flag->len, i, '0');
	}
	if (!flag->min)
	{
		if (flag->width)
			i += ft_putstr("0x");
		if (p || !(flag->prec < 0))
			i += ft_puthex(p, 'x');
	}
	return (i);
}

int		ft_p(va_list arg, t_flag *flag, int i)
{
	unsigned long long int p;

	p = va_arg(arg, unsigned long long int);
	flag->len = p_count(p);
	if (!p)
	{
		flag->len = 1;
		p = 0;
	}
	if (flag->prec && (flag->width || flag->zero || flag->min))
		i += ft_p_dot(flag, i, p);
	else if (flag->width || flag->min || flag->zero || flag->prec)
		i += ft_p_solo(flag, i, p);
	else
	{
		i += ft_putstr("0x");
		i += ft_puthex(p, 'x');
	}
	return (i);
}
