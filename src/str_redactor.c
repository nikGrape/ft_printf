/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_redactor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 20:09:48 by vinograd          #+#    #+#             */
/*   Updated: 2019/07/09 00:38:17 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*str_redactor(char *arg, register t_flag flags)
{
	char	*str;
	int		len;

	len = ft_strlen(arg);
	if (flags.width != -1 && flags.width < len && flags.spcf != '%')
	{
		arg[flags.width] = '\0';
		len = flags.width;
	}
	if (len < flags.length)
	{
		str = ft_strnew(flags.length - len);
		ft_memset(str, flags.filler, flags.length - len);
		arg = (flags.minus) ?\
		ft_strjoin_free(arg, str, 3) : ft_strjoin_free(str, arg, 3);
	}
	return (arg);
}

int		putstr_for_null_char(char *s)
{
	size_t i;

	i = 0;
	if (s != NULL)
		while (s[i] != '\0')
		{
			if (s[i] == '@')
				ft_putchar('^');
			ft_putchar(s[i++]);
		}
	return (i);
}
