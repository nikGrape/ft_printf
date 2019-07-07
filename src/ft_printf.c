/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 11:15:24 by vinograd          #+#    #+#             */
/*   Updated: 2019/07/06 18:08:38 by vinograd         ###   ########.fr       */
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
		str += (*str == '{') ? color_redactor(str) : 0;
		if (*str != '%')
		{
			ft_putchar(*str++);
			total++;
			continue ;
		}
		flags = flag_analazer(++str, &ap);
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
	int i;
	char str[] = "tadfsdfsd asdfa sdfasd fasd fasdf asdf";

	i = 768;
	ft_printf("{bold_red}%0*.5d {bold_blue}hello{bold_cyan} world\n{bold_yellow}%s\n{eoc}HEllo world\n", 10, i, str);
}
