/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redactor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 16:55:05 by vinograd          #+#    #+#             */
/*   Updated: 2019/06/25 00:53:05 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

	// int	steps; +
	// int hashtag;
	// int minus; +
	// int spase;
	// int plus;
	// int zero; +
	// int width; +
	// int length; +
	// int l_flag;
	// int h_flag;

char	*digit_redactor(char *s, int width)
{
	int		len;
	char	*str;

	len = ft_strlen(s);
	if (width > len)
	{
		str = ft_strnew(width - len);
		ft_memset(str, '0', width - len);
		return (ft_strjoin(str, s));
	}
	return (s);
}

char	*redactor(char *s, t_flag flags, int isdigit)
{
	int		len;
	char	ch;
	char	*str;

	len = ft_strlen(s);
	ch = (flags.zero) ? '0' : ' ';
	if (isdigit)
	{
		s = digit_redactor(s, flags.width);
		ch = (flags.width != -1) ? ' ' : '0';
	}
	else if (flags.width != -1)
		s[flags.width] = '\0';
	len = ft_strlen(s);
	if (len < flags.length)
	{
		str = ft_strnew(flags.length - len);
		ft_memset(str, ch, flags.length - len);
		return (flags.minus) ? ft_strjoin(s, str) : ft_strjoin(str, s);
	}
	return (s);
}
