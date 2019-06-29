/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 11:15:24 by vinograd          #+#    #+#             */
/*   Updated: 2019/06/28 22:53:52 by Nik              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		if (str[i] != '%')
		{
			ft_putchar(str[i++]);
			total++;
			continue ;
		}
		flags = flag_analazer(&str[++i]);
		i += flags.steps;
		if (!(s = specifier(str[i++], flags, &ap)))
			continue ;
		total += ft_strlen(s);
		ft_putstr(s);
		ft_strdel(&s);
	}
	va_end(ap);
	return (total);
}

// int		main()
// {
// 	ft_printf("%05p\n", 0);
// 	printf("%05p\n", 0);
// }
