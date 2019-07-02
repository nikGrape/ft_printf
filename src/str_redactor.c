/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_redactor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 10:41:01 by vinograd          #+#    #+#             */
/*   Updated: 2019/07/01 12:13:50 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*str_redactor(char *arg, register t_flag flags)
{
	char	*str;
	int		len;

	len = ft_strlen(arg);
	if (flags.width != -1 && flags.width < len)
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
