/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproveme <eproveme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 00:08:38 by eproveme          #+#    #+#             */
/*   Updated: 2021/01/16 01:29:37 by eproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

struct s_flag	null_flag(void)
{
	struct s_flag	flag;
	
	flag.width = 0;
	flag.min = 0;
	flag.zero = 0;
	flag.prec = 0;
	flag.dot = 0;
	flag.num = 0;
	flag.len = 0;
	return (flag);
};
