/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 13:07:55 by vinograd          #+#    #+#             */
/*   Updated: 2019/06/30 01:27:03 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <wchar.h>
# include "../libft/libft.h"
# include <stdio.h>

typedef struct	s_flags
{
	int		steps;
	char	spcf;
	char	filler;
	short	hashtag;
	short	minus;
	short	spase;
	short	plus;
	short	zero;
	short	width;
	short	length;
	short	l_flag;
	short	h_flag;
	short	j_flag;
	short	z_flag;
}				t_flag;

t_flag			flag_analazer(const char *s);
char			*redactor(char *arg, t_flag flags, char specifier);
char			*specifier(register char ch, t_flag flags, va_list *ap);

#endif
