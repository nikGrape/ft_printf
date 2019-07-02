/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 11:15:24 by vinograd          #+#    #+#             */
/*   Updated: 2019/07/02 13:10:22 by Nik              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *str, ...)
{
	va_list	ap;
	t_flag	flags;
	char	*s;
	int		total;

	total = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str != '%')
		{
			ft_putchar(*str++);
			total++;
			continue ;
		}
		flags = flag_analazer(++str);
		str += flags.steps;
		if (!(s = specifier(*str++, flags, &ap)))
			continue ;
		total += ft_putstr(s);
		ft_strdel(&s);
	}
	va_end(ap);
	return (total);
}

int		main(void)
{
	float i = -0.01;
	if (i < 0)
	{
		ft_printf("%.5f\n", -0.0);
		printf("%.5f\n", -0.0);
	}
}

	//  basic 1 (-12547.58)            : [SEGV]
	//  basic 2 (0)                    : [SEGV]
	//  basic 3 (45.123456789)         : [SEGV]
	//  basic 4 (12389123798)          : [KO]
	//  basic 5 (-8965421.12356432156) : [SEGV]
	//  special 1 (inf/-inf/nan)       : [KO]
	//  special 2 (-0.0)               : [KO]