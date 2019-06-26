/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 00:55:21 by vinograd          #+#    #+#             */
/*   Updated: 2019/06/26 02:05:52 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*specifier(char ch, t_flag flags, va_list *ap)
{
	char *s;

	if (ch == 's')
		s = redactor(ft_strdup(va_arg(*ap, char *)), flags, 0);
	else if (ch == 'c')
		s = redactor(ft_stradd(NULL, (char)va_arg(*ap, int)), flags, 0);
	else if (ch == 'd' || ch == 'i')
		s = redactor(ft_itoa(va_arg(*ap, int)), flags, 'd');
	else if (ch == 'u')
		s = redactor(ft_itoa_unsigned(va_arg(*ap, unsigned int)), flags, 1);
	else if (ch == 'f')
	{
		flags.width = (flags.width == -1) ? 6 : flags.width;
		s = redactor(ft_ftoa((float)va_arg(*ap, double), flags.width),\
		flags, 'f');
	}
	else if (ch == 'x')
		s = redactor(ft_itoa_base(va_arg(*ap, int), 16), flags, 'x');
	else if (ch == 'X')
	{
		s = redactor(ft_itoa_base(va_arg(*ap, int), 16), flags, 'x');
		ft_strupper(s);
	}
	else if (ch == 'o')
		s = redactor(ft_itoa_base(va_arg(*ap, int), 8), flags, 'o');
	else if (ch == 'p')
		s = redactor(ft_itoa_base_unsign(va_arg(*ap, size_t), 16), flags, 'p');
	return (NULL);
}
