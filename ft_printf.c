#include "ft_printf.h"

int	print_format(va_list arg, const char **format)
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

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		done;

	done = 0;
	va_start(arg, format);
	done = print_format(arg, &format);
	va_end(arg);
	return (done);
}
