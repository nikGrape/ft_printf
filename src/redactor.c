/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redactor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 16:55:05 by vinograd          #+#    #+#             */
/*   Updated: 2019/06/30 00:09:09 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*final_redactor(char *arg, register t_flag flags, int len)
{
	char			*str;
	char			*dash;

	dash = ft_strchr(arg, '-');
	if (len < flags.length)
	{
		str = ft_strnew(flags.length - len);
		ft_memset(str, flags.filler, flags.length - len);
		if (flags.spcf == 'd' && flags.spase && flags.filler == '0' && !dash)
			str[0] = ' ';
		arg = (flags.minus || flags.spcf == 'p') ?\
		ft_strjoin_free(arg, str, 3) : ft_strjoin_free(str, arg, 3);
		dash =\
		(flags.spcf != 's' && flags.spcf != 'c') ? ft_strchr(arg, '-') : NULL;
		if (dash && flags.filler == '0')
			ft_swap(arg, dash);
		if (flags.hashtag && flags.filler == '0' && (str = ft_strchr(arg, 'x')))
			ft_swap(str, arg + 1);
		if (!dash && flags.plus && flags.filler == '0' &&\
		(flags.spcf == 'd' || flags.spcf == 'f'))
			ft_swap(ft_strchr(arg, '0'), ft_strchr(arg, '+'));
	}
	else if (flags.spase && flags.spcf == 'd' && !dash)
		arg = ft_strjoin_free(" ", arg, 2);
	return (arg);
}

static char	*hashtag_redactor(register int specifier, char *arg, short width)
{
	if (!ft_strcmp(arg, "0") && specifier != 'p')
		return (arg);
	if (!ft_strcmp(arg, "0") && specifier == 'p' && !width)
		arg[0] = '\0';
	if (specifier == 'x' || specifier == 'p')
		return (ft_strjoin_free("0x", arg, 2));
	if (specifier == 'o')
		return (ft_strjoin_free("0", arg, 2));
	return (arg);
}

static char	*add_zeros(char *arg, char *dash, short width)
{
	int		len;
	char	*str;

	len = (dash) ? ft_strlen(arg) - 1 : ft_strlen(arg);
	if (width > len)
	{
		str = ft_strnew(width - len);
		ft_memset(str, '0', width - len);
		str = ft_strjoin_free(str, arg, 3);
		if (dash)
			ft_swap(ft_strchr(str, '-'), str);
		return (str);
	}
	return (arg);
}

static char	*digit_redactor(char *arg, char *dash, register t_flag flags)
{
	register int	spcf;

	spcf = flags.spcf;
	arg = add_zeros(arg, dash, flags.width);
	if (flags.hashtag || spcf == 'p')
		arg = hashtag_redactor(spcf, arg, flags.width);
	if (!flags.width && !ft_strcmp(arg, "0") &&\
	(spcf == 'x' || spcf == 'o' || spcf == 'd')\
	&& !(flags.hashtag && spcf == 'o'))
		arg[0] = '\0';
	if (!dash && flags.plus && (spcf == 'd' || spcf == 'f'))
		arg = ft_strjoin_free("+", arg, 2);
	return (arg);
}

char		*redactor(char *arg, t_flag flags, char specifier)
{
	flags.spcf = specifier;
	if (flags.spcf != 's' && flags.spcf != 'c')
	{
		arg = digit_redactor(arg, ft_strchr(arg, '-'), flags);
		flags.filler = (flags.width != -1) ? ' ' : flags.filler;
	}
	else if (flags.width != -1 && flags.width < (int)ft_strlen(arg))
		arg[flags.width] = '\0';
	arg = final_redactor(arg, flags, ft_strlen(arg));
	return (arg);
}
