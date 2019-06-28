/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 00:55:21 by vinograd          #+#    #+#             */
/*   Updated: 2019/06/27 22:56:54 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*specifier(char ch, t_flag flags, va_list *ap)
{
	char *s;

	s = NULL;
	if (ch == 's')
	{
		s = va_arg(*ap, char *);
		s = (s) ? redactor(ft_strdup(s), flags, 0) :\
		redactor(ft_strdup("(null)"), flags, 0);
	}
	else if (ch == 'c')
	{
		ch = (char)va_arg(*ap, int);
		s = (ch == 0) ? redactor(ft_strdup("^@"), flags, 0)\
		: redactor(ft_stradd(NULL, ch), flags, 0);
	}
	else if (ch == 'd' || ch == 'i')
	{
		s = redactor(ft_itoa(va_arg(*ap, int)), flags, 'd');
	}
	else if (ch == 'u' || ch == 'U')
		s = redactor(ft_itoa_unsigned(va_arg(*ap, unsigned int)), flags, 1);
	else if (ch == 'f')
	{
		flags.width = (flags.width == -1) ? 6 : flags.width;
		s = redactor(ft_ftoa((float)va_arg(*ap, double), flags.width),\
		flags, 'f');
	}
	else if (ch == 'x')
		s = (flags.j_flag || flags.l_flag) ? redactor(ft_itoa_base_unsign\
		(va_arg(*ap, size_t), 16), flags, 'x') :\
		redactor(ft_itoa_base(va_arg(*ap, int), 16), flags, 'x');
	else if (ch == 'X')
	{
		s = (flags.j_flag || flags.l_flag) ? redactor(ft_itoa_base_unsign\
		(va_arg(*ap, size_t), 16), flags, 'x') :\
		redactor(ft_itoa_base(va_arg(*ap, int), 16), flags, 'x');
		ft_strupper(s);
	}
	else if (ch == 'o')
		s = redactor(ft_itoa_base(va_arg(*ap, int), 8), flags, 'o');
	else if (ch == 'p')
		s = redactor(ft_itoa_base_unsign(va_arg(*ap, size_t), 16), flags, 'p');
	else if (ch == '%')
		s = redactor(ft_strdup("%"), flags, 1);
	return (s);
}
