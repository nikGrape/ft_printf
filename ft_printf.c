/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 11:15:24 by vinograd          #+#    #+#             */
/*   Updated: 2019/06/25 01:05:13 by vinograd         ###   ########.fr       */
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

	i = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] != '%')
		{
			ft_putchar(str[i++]);
			continue ;
		}
		flags = flag_analazer(&str[++i]);
		i += flags.steps;
		s = specifier(str[i++], flags, &ap);
		ft_putstr(s);
	}
	va_end(ap);
	return (i);
}

int		main()
{
	float f = 145.123222;
	char s[] = "hello world and piece";
	ft_printf("Hello %08.2d world %f\n%30sa\n%05.4x\n", 121111, f, s, 42344);
	   printf("Hello %08.2d world %f\n%30sa\n%05.4x\n", 121111, f, s, 42344);
	ft_printf("%p\n", s);
	printf("%p\n", s);
}
