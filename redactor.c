/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redactor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 16:55:05 by vinograd          #+#    #+#             */
/*   Updated: 2019/06/28 17:50:30 by Nik              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	specifier 0 - str or char
**	specifier 1 - int or float
**	specifier x - hex or HEX
**	specifier o - oct
**	specifier p - memory
*/

#include "ft_printf.h"

static char	*hashtag_redactor(int specifier, char *arg)
{
	if (!ft_strcmp(arg, "0"))
		return (arg);
	if (specifier == 'x' || specifier == 'p')
		return (ft_strjoin_free("0x", arg, 2));
	if (specifier == 'o')
		return (ft_strjoin_free("0", arg, 2));
	return (arg);
}

static char	*add_zeros(char *arg, char *dash, t_flag flags)
{
	int		len;
	char	*str;

	len = ft_strlen(arg);
	if (flags.width > len)
	{
		len = (dash) ? len - 1 : len;
		str = ft_strnew(flags.width - len);
		ft_memset(str, '0', flags.width - len);
		str = ft_strjoin_free(str, arg, 3);
		if (dash)
			ft_swap(ft_strchr(str, '-'), str);
		return (str);
	}
	return (arg);
}

static char	*digit_redactor(char *arg, char *dash, t_flag flags)
{
		arg = add_zeros(arg, dash, flags);
		if (flags.hashtag || flags.spcf == 'p')
			arg = hashtag_redactor(flags.spcf, arg);
		if (!flags.width && !ft_strcmp(arg, "0") &&\
		(flags.spcf == 'x' || flags.spcf == 'o' || flags.spcf == 'd')\
		&& !(flags.hashtag && flags.spcf == 'o'))
			arg[0] = '\0';
		if (!dash && flags.plus && (flags.spcf == 'd' || flags.spcf == 'f'))
			arg = ft_strjoin_free("+", arg, 2);
		return (arg);
}

static char	*finil_redactor(char *arg, t_flag flags, int len)
{
	char *str;
	char *dash;

	if (len < flags.length)
	{
		str = ft_strnew(flags.length - len);
		ft_memset(str, flags.filler, flags.length - len);
		arg = (flags.minus) ? ft_strjoin_free(arg, str, 3) : ft_strjoin_free(str, arg, 3);
		dash =  (flags.spcf != 's' && flags.spcf != 'c') ? ft_strchr(arg, '-') : NULL;
		if (dash && flags.filler == '0')
			ft_swap(arg, dash);
		if (flags.hashtag && flags.filler == '0' && (str = ft_strchr(arg, 'x')))
			ft_swap(str, arg + 1);
		if (!dash && (flags.spcf == 'd' || flags.spcf == 'f') && flags.plus && flags.filler == '0')
			ft_swap(ft_strchr(arg, '0'), ft_strchr(arg, '+'));
	}
	return (arg);
}

char		*redactor(char *arg, t_flag flags, int specifier)
{
	flags.spcf = specifier;	
	if (flags.spcf != 's' && flags.spcf != 'c')
	{
		arg = digit_redactor(arg, ft_strchr(arg, '-'), flags);
		flags.filler = (flags.width != -1) ? ' ' : flags.filler;
	}
	else if (flags.width != -1 && flags.width < (int)ft_strlen(arg))
		arg[flags.width] = '\0';
	arg = finil_redactor(arg, flags, ft_strlen(arg));
	return (arg);
}
