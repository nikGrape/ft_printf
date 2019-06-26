/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redactor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 16:55:05 by vinograd          #+#    #+#             */
/*   Updated: 2019/06/26 02:06:51 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**		int	steps; +
**		int hashtag;
**		int minus; +
**		int spase;
**		int plus;
**		int zero; +
**		int width; +
**		int length; +
**		int l_flag;
**		int h_flag;
**
**	specifier 0 - str or char
**	specifier 1 - int or float
**	specifier 2 - hex or HEX
**	specifier 3 - oct
**	specifier 4 - memory
*/

#include "ft_printf.h"

static char	*hashtag_redactor(int specifier, char *arg)
{
	if (specifier == 'x' || specifier == 'p')
		return (ft_strjoin_free("Ox", arg, 2));
	if (specifier == 'o')
		return (ft_strjoin_free("0", arg, 2));
	return (arg);
}

static char	*digit_redactor(char *s, int width)
{
	int		len;
	char	*str;

	len = ft_strlen(s);
	if (width > len)
	{
		str = ft_strnew(width - len);
		ft_memset(str, '0', width - len);
		return (ft_strjoin_free(str, s, 3));
	}
	return (s);
}

char		*redactor(char *arg, t_flag flags, int specifier)
{
	int		len;
	char	ch;
	char	*str;

	ch = (flags.zero) ? '0' : ' ';
	if (specifier)
	{
		arg = digit_redactor(arg, flags.width);
		if (flags.hashtag || specifier == 'p')
			arg = hashtag_redactor(specifier, arg);
		if (flags.plus && (specifier == 'd' || specifier == 'f'))
			arg = ft_strjoin_free("+", arg, 2);
		ch = (flags.width != -1) ? ' ' : ch;
	}
	else if (flags.width != -1 && flags.width < (int)ft_strlen(arg))
		arg[flags.width] = '\0';
	len = ft_strlen(arg);
	if (len < flags.length)
	{
		str = ft_strnew(flags.length - len);
		ft_memset(str, ch, flags.length - len);
		return (flags.minus) ?\
		ft_strjoin_free(arg, str, 3) : ft_strjoin_free(str, arg, 3);
	}
	return (arg);
}
