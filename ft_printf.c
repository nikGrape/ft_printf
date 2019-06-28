/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 11:15:24 by vinograd          #+#    #+#             */
/*   Updated: 2019/06/27 18:33:59 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <wchar.h>

int		ft_printf(const char *str, ...)
{
	va_list	ap;
	t_flag	flags;
	char	*s;
	int		i;
	int		total;

	i = 0;
	total = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] != '%' || (str[i] == '%' && str[i + 1] == '%'))
		{
			i += (str[i] == '%' && str[i + 1] == '%') ? 1 : 0;
			ft_putchar(str[i++]);
			total++;
			continue ;
		}
		flags = flag_analazer(&str[++i]);
		i += flags.steps;
		s = specifier(str[i++], flags, &ap);
		total += ft_strlen(s);
		ft_putstr(s);
		ft_strdel(&s);
	}
	va_end(ap);
	return (total);
}

int		main()
{
	float f = 150.123445;
	int i = -214;
	unsigned int j;
	char s[] = "hello world and piece";
	int a = ft_printf("%-30.20sr%%lol %#o\n", s, i);
	printf("%d\n", a);
	a = printf("%-30.20sr%%lol %#o\n", s, (int)i);
	printf("% c\n", 0);
	ft_printf("%#08x\n", 42);
	printf("% d\n", 42);
}
