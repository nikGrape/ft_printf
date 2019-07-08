/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 11:15:24 by vinograd          #+#    #+#             */
/*   Updated: 2019/07/08 12:36:03 by Nik              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	t_flag	flags;
	char	*s;
	int		total;

	total = 0;
	va_start(ap, format);
	while (*format)
	{
		format += (*format == '{') ? color_redactor(format) : 0; //can be \0
		if (*format != '%' && *format)
		{
			ft_putchar(*format++);
			total++;
			continue ;
		}
		if (!*format)
			break ;
		flags = flag_analazer(++format, &ap);// can be \0
		format += flags.steps;
		if (!(s = specifier(*format, flags, &ap)))
			continue ;
		format++;
		total += ft_putstr(s);
		ft_strdel(&s);
	}
	va_end(ap);
	return (total);
}

int main()
{
	//ft_printf("{bold_green}-> {bold_cyan}src {bold_blue}git:({bold_red}master{bold_blue}) {bold_yellow}x{eoc} gcc *.c ../libft.a\n");
	ft_printf("{red}%5d{eoc}", 776);
	ft_putchar(0);
	//ft_printf("%");
	//printf("%");
	// ft_printf("%llf  %f  %lf\n", 1.42, 1.42, 1.42L);
	// printf("{%f}{%lf}{%Lf}\n", 1.42, 1.42, 1.42l);
	// ft_printf("%o, %ho, %hho\n", -42, -42, -42);	
	// printf("%o, %ho, %hho\n", -42, -42, -42);
}