/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 00:55:21 by vinograd          #+#    #+#             */
/*   Updated: 2019/06/25 01:07:09 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*specifier(char ch, t_flag flags, va_list *ap)
{
	char *s;

	if (ch == 's')
		s = redactor(va_arg(*ap, char *), flags, 0);
	else if (ch == 'd' || ch == 'i')
		s = redactor(ft_itoa(va_arg(*ap, int)), flags, 1);
	else if (ch == 'f')
		s = redactor(ft_ftoa((float)va_arg(*ap, double)), flags, 1);
	else if (ch == 'c')
		s = redactor(ft_stradd(NULL, (char)va_arg(*ap, int)), flags, 0);
	else if (ch == 'x')
		s = redactor(ft_itoa_base(va_arg(*ap, int), 16), flags, 1);
	else if (ch == 'X')
		s = redactor(ft_itoa_base(va_arg(*ap, int), 16), flags, 1);
	else if (ch == 'p')
	{
		s = redactor(ft_itoa_base_unsign(va_arg(*ap, size_t), 16), flags, 1);
		ft_putstr("0x");
	}
	return (s);
}
