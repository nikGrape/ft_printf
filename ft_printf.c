/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 11:15:24 by vinograd          #+#    #+#             */
/*   Updated: 2019/06/22 17:31:58 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <wchar.h>

int		ft_printf(const char *str, ...)
{
	int		i;
	va_list	ap;
	t_flag flag;
	
	i = 0;
	va_start(ap, str);
	int i = va_arg(ap, int);
	char ch = va_arg(ap, int);
	while (str[i])
	{
		if (str[i] != '%')
		{
			ft_putchar(str[i++]);
			continue ;
		}
		flag = flag_analazer(str);
		if (str[++i] == 's')
			ft_putstr(va_arg(ap, char *));
		else if (str[i] == 'd' || str[i] == 'i')
			ft_putnbr(va_arg(ap, int));
		else if (str[i] == 'c')
			ft_putchar(va_arg(ap, int));
		else if (str[i] == 'x')
			print_hex(va_arg(ap, int), 0);
		else if (str[i] == 'X')
			print_hex(va_arg(ap, int), 1);
		else if (str[i] == 'p')
			print_hex(va_arg(ap, size_t), 0);
		i++;
	}
	va_end(ap);
	return (i);
}
#include <stdio.h>

union		s_un
{
	int		i;
	char	c;
	char	*s;
	float	f;
}			t_un;

int		main()
{
	int a = 45;
	union s_un un;
	un.i = a;
	un.c = 'c';
	ft_printf("Hello %d world %d\n lol\n", un, 54);
	ft_printf("0x    %p\n", &a);
	printf("%p\n", &a);
	ft_printf("%x\n", -42);
	printf("%x\n", -42);
}
