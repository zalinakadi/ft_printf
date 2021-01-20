/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproveme <eproveme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:05:47 by eproveme          #+#    #+#             */
/*   Updated: 2021/01/20 19:50:28 by eproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

struct			s_flag
{
	int			width;
	int			min;
	int			zero;
	int			prec;
	int			dot;
	int			num;
	int			len;
};

int				ft_printf(const char *format, ...);
int				print_format(va_list arg, const char **format);
void			ft_parser(va_list arg, const char **format,
							struct s_flag *flag);
int				ft_specs(va_list arg, const char **format,
							struct s_flag *flag, int i);
int				ft_d_i(va_list arg, struct s_flag *flag, int i);
int				ft_str(va_list arg, struct s_flag *flag, int i);
int				ft_u(va_list arg, struct s_flag *flag, int i);
int				ft_x(va_list arg, struct s_flag *flag, int i);
int				ft_hex(va_list arg, struct s_flag *flag, int i);
int				ft_p(va_list arg, struct s_flag *flag, int i);
int				sign_num(va_list arg, const char **format);
int				none_spec(int n);
int				ft_putchar(char c);
int				ft_putstr(char *s);
int				ft_isdigit(int c);
int				ft_atoi(const char *str);
int				ft_putnbr(long int n);
int				ft_putunbr(unsigned int n);
int				ft_puthex(unsigned long long int n, int spec);
struct s_flag	null_flag(void);
void			num_flag(struct s_flag *flag);
void			dot_flag(struct s_flag *flag, char c);
int				ft_putsmth(int a, int b, int i, char c);
int				x_count(unsigned int n);
size_t			ft_strlen(const char *str);
int				ft_toupper(int c);

#endif
