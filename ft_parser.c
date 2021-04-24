#include "ft_printf.h"

void	parse_dot(va_list arg, const char **format, t_flag *flag)
{
	flag->prec = sign_num(arg, &(*format));
	if (flag->prec == 0)
		flag->prec = -1;
	else if (flag->prec < 0)
		flag->prec = 0;
}

void	parse_zero(va_list arg, const char **format, t_flag *flag)
{
	while (**format == '0')
		(*format)++;
	if (**format == '-')
	{
		(*format)++;
		if (ft_isdigit(**format) || **format == '*')
			flag->min = sign_num(arg, &(*format));
		else
			(*format)--;
	}
	else if (ft_isdigit(**format) || **format == '*')
	{
		flag->zero = sign_num(arg, &(*format));
		if (flag->zero < 0)
		{
			flag->min = -flag->zero;
			flag->zero = 0;
		}
	}
	else
		(*format)--;
}

void	parse_min(va_list arg, const char **format, t_flag *flag)
{
	if (flag->zero != -1)
		(*format)++;
	if (**format != '.')
	{
		if (ft_isdigit(**format) || **format == '*')
		{
			flag->min = sign_num(arg, &(*format));
			if (flag->min < 0)
				flag->min = -flag->min;
		}
		else
			(*format)--;
	}
	else
		(*format)--;
}

void	parse_width(va_list arg, const char **format, t_flag *flag)
{
	flag->width = sign_num(arg, &(*format));
	if (flag->width < 0)
	{
		flag->min = -flag->width;
		flag->width = 0;
	}
}

void	ft_parser(va_list arg, const char **format, t_flag *flag)
{
	while (none_spec(**format))
	{
		if ((ft_isdigit(**format) && **format != '0') || **format == '*')
			parse_width(arg, &(*format), flag);
		else if (**format == '-')
			parse_min(arg, &(*format), flag);
		else if (**format == '0')
		{
			(*format)++;
			if (!none_spec(**format))
				break ;
			parse_zero(arg, &(*format), flag);
		}
		else if (**format == '.')
		{
			flag->prec = -1;
			(*format)++;
			if (!none_spec(**format))
				break ;
			parse_dot(arg, &(*format), flag);
		}
		(*format)++;
	}
}
