/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproveme <eproveme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:04:42 by eproveme          #+#    #+#             */
/*   Updated: 2021/01/21 16:32:08 by eproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_format(va_list arg, const char **format)
{
	t_flag	flag;
	int		i;

	i = 0;
	while (**format)
	{
		if (**format == '%')
		{
			null_flag(&flag);
			(*format)++;
			if (**format == '\0')
				return (i);
			else if (**format == ' ')
				i += ft_putchar(' ');
			ft_parser(arg, &(*format), &flag);
			i += ft_specs(arg, &(*format), &flag, i);
		}
		else
			i += ft_putchar(**format);
		(*format)++;
	}
	return (i);
}

int		ft_printf(const char *format, ...)
{
	va_list arg;
	int		done;

	done = 0;
	va_start(arg, format);
	done = print_format(arg, &format);
	va_end(arg);
	return (done);
}
