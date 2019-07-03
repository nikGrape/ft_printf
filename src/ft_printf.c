/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 11:15:24 by vinograd          #+#    #+#             */
/*   Updated: 2019/07/02 17:45:12 by Nik              ###   ########.fr       */
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

// int		main(void)
// {
// 	float i = -0.0;
// 	ft_printf("%06.0% %-10.0sa\n", "Hello");
// 	printf("%06.0% %-10.0sa\n", "Hello");
// }