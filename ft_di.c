#include "ft_printf.h"

int	di_count(long int n)
{
	int	i;

	i = 1;
	if (n != 0)
	{
		if (n < 0)
		{
			n = -n;
			i++;
		}
		while (n >= 10)
		{
			n = n / 10;
			i++;
		}
	}
	return (i);
}

int	ft_di_mindot(t_flag *flag, int i, int n)
{
	i = 0;
	num_flag(flag);
	flag->len = di_count(n);
	if (n < 0 && n > -2147483648)
	{
		flag->prec++;
		i += ft_putchar('-');
		n = -n;
	}
	else if (n == 0 && flag->prec == -1)
		flag->num++;
	dot_flag(flag, 'i');
	i += ft_putsmth(flag->prec, flag->len, i, '0');
	if (flag->prec != -1 || n != 0)
		i += ft_putnbr(n);
	i += ft_putsmth(flag->num, flag->dot, i, ' ');
	return (i);
}

int	ft_di_plusdot(t_flag *flag, int i, int n)
{
	i = 0;
	num_flag(flag);
	dot_flag(flag, 'i');
	if ((flag->prec == -1 && n == 0) && !flag->zero)
		flag->num++;
	else if (n < 0 && (flag->prec >= flag->len))
		flag->num--;
	else if (n == 0 && (flag->prec < flag->len))
		flag->num++;
	i += ft_putsmth(flag->num, flag->dot, i, ' ');
	if (n < 0 && n > -2147483648)
	{
		i += ft_putchar('-');
		n = -n;
		flag->len--;
	}
	i += ft_putsmth(flag->prec, flag->len, i, '0');
	if (flag->prec != -1 || n != 0)
		i += ft_putnbr(n);
	return (i);
}

int	ft_di_solo(t_flag *flag, int i, int n)
{
	i = 0;
	num_flag(flag);
	if ((n < 0 && n > -2147483648) && !flag->width)
	{
		i += ft_putchar('-');
		n = -n;
		if (flag->prec)
			flag->num++;
	}
	if (flag->min)
		i += ft_putnbr(n);
	while ((flag->num - flag->len) > 0)
	{
		if (flag->width || flag->min)
			i += ft_putchar(' ');
		else if (flag->zero || flag->prec)
			i += ft_putchar('0');
		flag->num--;
	}
	if (!flag->min && (flag->prec != -1 || n != 0))
		i += ft_putnbr(n);
	return (i);
}

int	ft_d_i(va_list arg, t_flag *flag, int i)
{
	int	n;

	i = 0;
	n = va_arg(arg, int);
	flag->len = di_count(n);
	if ((flag->width && flag->prec) || (flag->zero && flag->prec))
		i += ft_di_plusdot(flag, i, n);
	else if (flag->min && flag->prec)
		i += ft_di_mindot(flag, i, n);
	else if (flag->width || flag->zero || flag->min || flag->prec)
		i += ft_di_solo(flag, i, n);
	else
		i += ft_putnbr(n);
	return (i);
}
