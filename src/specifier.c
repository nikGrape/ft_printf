/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 00:55:21 by vinograd          #+#    #+#             */
/*   Updated: 2019/06/28 21:07:37 by Nik              ###   ########.fr       */
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
		s = (s) ? redactor(ft_strdup(s), flags, 's') :\
		redactor(ft_strdup("(null)"), flags, 's');
	}
	else if (ch == 'c')
	{
		ch = (char)va_arg(*ap, int);
		if (ch == 0)
			s = redactor(s = ft_strdup("@"), flags, 'c');
		else
			s = redactor(ft_stradd(NULL, ch), flags, 'c');
	}
	else if (ch == 'd' || ch == 'i')
	{
		if (flags.h_flag == 1)
			s = ft_itoa((short)va_arg(*ap, int));
		else if (flags.h_flag == 2)
			s = ft_itoa((signed char)va_arg(*ap, int));
		else if (flags.l_flag == 1)
			s = ft_itoa_long(va_arg(*ap, long));
		else if (flags.l_flag == 2 || flags.j_flag || flags.z_flag)
			s = ft_itoa_long(va_arg(*ap, long));
		else
			s = ft_itoa(va_arg(*ap, int));
		s = redactor(s, flags, 'd');
	}
	else if (ch == 'u' || ch == 'U')
	{

		if (ch == 'U' || flags.l_flag || flags.j_flag || flags.z_flag)
			s = ft_itoa_unsigned(va_arg(*ap, unsigned long));
		else
			s = ft_itoa_unsigned(va_arg(*ap, unsigned int));
		s = redactor(s, flags, 'u');
	}
	else if (ch == 'f')
	{
		flags.width = (flags.width == -1) ? 6 : flags.width;
		s = redactor(ft_ftoa((float)va_arg(*ap, double), flags.width), flags, 'f');
	}
	else if (ch == 'X' || ch == 'x')
	{
		s = (flags.j_flag || flags.l_flag) ? redactor(ft_itoa_base_unsigned\
		(va_arg(*ap, size_t), 16), flags, 'x') :\
		redactor(ft_itoa_base(va_arg(*ap, int), 16), flags, 'x');
		if (ch == 'X')
			ft_strupper(s);
	}
	else if (ch == 'o')
		s = redactor(ft_itoa_base(va_arg(*ap, int), 8), flags, 'o');
	else if (ch == 'p')
		s = redactor(ft_itoa_base_unsigned(va_arg(*ap, size_t), 16), flags, 'p');
	else if (ch == '%')
		s = redactor(ft_strdup("%"), flags, 1);
	else
		s = redactor(ft_strdup(""), flags, 's');
	return (s);
}
