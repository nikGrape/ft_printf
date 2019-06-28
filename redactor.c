/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redactor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 16:55:05 by vinograd          #+#    #+#             */
/*   Updated: 2019/06/27 17:12:10 by vinograd         ###   ########.fr       */
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
		return (ft_strjoin_free("0x", arg, 2));
	if (specifier == 'o')
		return (ft_strjoin_free("0", arg, 2));
	return (arg);
}

static char	*digit_redactor(char *arg, char *dash, int width)
{
	int		len;
	char	*str;

	len = ft_strlen(arg);
	dash = ft_strchr(arg, '-');
	if (width > len)
	{
		len = (dash) ? len - 1 : len;
		str = ft_strnew(width - len);
		ft_memset(str, '0', width - len);
		str = ft_strjoin_free(str, arg, 3);
		if (dash)
			ft_swap(ft_strchr(str, '-'), str);
		return (str);
	}
	return (arg);
}

char		*redactor(char *arg, t_flag flags, int specifier)
{
	int		len;
	char	ch;
	char	*str;
	char	*dash;

	ch = (flags.zero) ? '0' : ' ';
	dash = ft_strchr(arg, '-');
	if (specifier)
	{
		arg = digit_redactor(arg, dash, flags.width);
		if (flags.hashtag || specifier == 'p')
			arg = hashtag_redactor(specifier, arg);
		if (!dash && flags.plus && (specifier == 'd' || specifier == 'f'))
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
		str = (flags.minus) ? ft_strjoin_free(arg, str, 3) : ft_strjoin_free(str, arg, 3);
		if (dash && ch == '0')
			ft_swap(str, ft_strchr(str, '-'));
		// if (flags.hashtag || specifier == 'p')
		//  	arg = hashtag_redactor(specifier, arg);
		return (str);
	}
	return (arg);
}
