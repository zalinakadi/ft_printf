#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s[i])
	{
		while (s[i] != '\0')
		{
			write(1, &s[i], 1);
			i++;
		}
	}
	return (i);
}

int	ft_putnbr(long int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
		i += ft_putstr("-2147483648");
	if (n < 0 && n > -2147483648)
	{
		i += ft_putchar('-');
		n = -n;
	}
	if (n < 10 && n > -2147483648)
	{
		i += ft_putchar(n + '0');
	}
	else if (n > 9)
	{
		i += ft_putnbr(n / 10);
		i += ft_putnbr(n % 10);
	}
	return (i);
}

int	ft_putunbr(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		i += ft_putchar('0');
	else if (n > 9)
	{
		i += ft_putunbr(n / 10);
		i += ft_putunbr(n % 10);
	}
	else if (n < 10)
	{
		i += ft_putchar(n + '0');
	}
	return (i);
}

int	ft_puthex(unsigned long long int n, int spec)
{
	int	i;

	i = 0;
	if (n == 0)
		i += ft_putchar('0');
	else if (n >= 16)
	{
		i += ft_puthex(n / 16, spec);
		i += ft_puthex(n % 16, spec);
	}
	else if (n < 10)
	{
		i += ft_putchar(n + '0');
	}
	else if (n > 9)
	{
		if (spec == 'x')
			i += ft_putchar(n + 87);
		else if (spec == 'X')
			i += ft_putchar(ft_toupper(n + 87));
	}
	return (i);
}
