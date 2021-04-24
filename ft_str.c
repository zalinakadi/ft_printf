#include "ft_printf.h"

int	ft_s_mindot(t_flag *flag, int i, char *s)
{
	dot_flag(flag, 's');
	while (flag->dot > 0)
	{
		i += ft_putchar(*s);
		s++;
		flag->dot--;
	}
	if (flag->prec == -1)
		flag->min--;
	dot_flag(flag, 's');
	i += ft_putsmth(flag->min, flag->dot, i, ' ');
	return (i);
}

int	ft_s_plusdot(t_flag *flag, int i, char *s)
{
	char	*str;

	str = "(null)";
	num_flag(flag);
	dot_flag(flag, 's');
	if (flag->prec == -1)
		flag->num--;
	else if (s == str)
		flag->prec = 0;
	i += ft_putsmth(flag->num, flag->dot, i, ' ');
	while (flag->dot > 0)
	{
		i += ft_putchar(*s);
		s++;
		flag->dot--;
	}
	return (i);
}

int	ft_str_solo(t_flag *flag, int i, char *s)
{
	i = 0;
	num_flag(flag);
	if (!flag->min && !flag->prec)
	{
		if (flag->width)
			i += ft_putsmth(flag->num, flag->len, i, ' ');
		else if (flag->zero)
			i += ft_putsmth(flag->num, flag->len, i, '0');
	}
	if ((flag->prec >= flag->len) || !flag->prec)
		i += ft_putstr(s);
	else if (flag->prec < flag->len)
	{
		while (flag->prec > 0)
		{
			i += ft_putchar(*s);
			s++;
			flag->prec--;
		}
	}
	if (flag->min)
		i += ft_putsmth(flag->num, flag->len, i, ' ');
	return (i);
}

int	ft_str(va_list arg, t_flag *flag, int i)
{
	char	*s;

	s = va_arg(arg, char *);
	if (!s)
		s = "(null)";
	flag->len = ft_strlen(s);
	if ((flag->width && flag->prec) || (flag->zero && flag->prec))
		i += ft_s_plusdot(flag, i, s);
	else if (flag->min && flag->prec)
		i += ft_s_mindot(flag, i, s);
	else if (flag->width || flag->min || flag->zero || flag->prec)
		i += ft_str_solo(flag, i, s);
	else
		i += ft_putstr(s);
	return (i);
}
