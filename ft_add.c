/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproveme <eproveme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 13:06:10 by eproveme          #+#    #+#             */
/*   Updated: 2021/01/20 13:23:48 by eproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	dot_flag(struct s_flag *flag, char c)
{
	if (c == 'i')
	{
		if (flag->prec > flag->len)
			flag->dot = flag->prec;
		else
			flag->dot = flag->len;
	}
	else if (c == 's')
	{
		if (flag->prec >= flag->len)
			flag->dot = flag->len;
		else
			flag->dot = flag->prec;
	}
}

void	num_flag(struct s_flag *flag)
{
	if (flag->width)
		flag->num = flag->width;
	else if (flag->zero)
		flag->num = flag->zero;
	else if (flag->min)
		flag->num = flag->min;
	else if (flag->prec)
		flag->num = flag->prec;
}

int		ft_atoi(const char *str)
{
	long long	num;
	int			i;
	int			sign;

	num = 0;
	i = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-')
		sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = 10 * num + (str[i] - '0') * sign;
		i++;
		if (num > 0 && sign < 0)
			return (0);
		if (num < 0 && sign > 0)
			return (-1);
	}
	return (num);
}

int		sign_num(va_list arg, const char **format)
{
	int		n;

	n = 0;
	if (ft_isdigit(**format))
	{
		n = ft_atoi(*format);
		while (ft_isdigit(*(*format + 1)))
			(*format)++;
	}
	else if (**format == '*')
		n = va_arg(arg, int);
	return (n);
}
