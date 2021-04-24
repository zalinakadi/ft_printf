#include "ft_printf.h"

int	u_count(unsigned int n)
{
	int	i;

	i = 1;
	if (n != 0)
	{
		while (n >= 10)
		{
			n = n / 10;
			i++;
		}
	}
	return (i);
}

int	ft_u_mindot(t_flag *flag, int i, unsigned int u)
{
	i = 0;
	if (flag->prec == -1 && u == 0)
		flag->min++;
	i += ft_putsmth(flag->prec, flag->len, i, '0');
	if (flag->prec != -1 || u != 0)
		i += ft_putunbr(u);
	dot_flag(flag, 'i');
	i += ft_putsmth(flag->min, flag->dot, i, ' ');
	return (i);
}

int	ft_u_plusdot(t_flag *flag, int i, unsigned int u)
{
	i = 0;
	num_flag(flag);
	if (flag->prec == -1 && u == 0)
		flag->num++;
	dot_flag(flag, 'i');
	i += ft_putsmth(flag->num, flag->dot, i, ' ');
	i += ft_putsmth(flag->prec, flag->len, i, '0');
	if (flag->prec != -1 || u != 0)
		i += ft_putunbr(u);
	return (i);
}

int	ft_u_solo(t_flag *flag, int i, unsigned int u)
{
	i = 0;
	num_flag(flag);
	if (flag->prec == -1 && u == 0)
		flag->num++;
	if (flag->min)
		i += ft_putunbr(u);
	if (flag->width || flag->min)
		i += ft_putsmth(flag->num, flag->len, i, ' ');
	else if (flag->zero || flag->prec)
		i += ft_putsmth(flag->num, flag->len, i, '0');
	if (!flag->min && (flag->prec != -1 || u != 0))
		i += ft_putunbr(u);
	return (i);
}

int	ft_u(va_list arg, t_flag *flag, int i)
{
	unsigned int	u;

	u = va_arg(arg, unsigned int);
	flag->len = u_count(u);
	if ((flag->width && flag->prec) || (flag->zero && flag->prec))
		i += ft_u_plusdot(flag, i, u);
	else if (flag->min && flag->prec)
		i += ft_u_mindot(flag, i, u);
	else if (flag->width || flag->min || flag->zero || flag->prec)
		i += ft_u_solo(flag, i, u);
	else
		i += ft_putunbr(u);
	return (i);
}
