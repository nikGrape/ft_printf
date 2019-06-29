/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 13:07:55 by vinograd          #+#    #+#             */
/*   Updated: 2019/06/28 14:31:01 by Nik              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"
# include <stdio.h>

typedef struct	s_flags
{
	int		steps;
	char	spcf;
	char	filler;
	int		hashtag;
	int		minus;
	int		spase;
	int		plus;
	int		zero;
	int		width;
	int		length;
	int		l_flag;
	int		h_flag;
	int		j_flag;
	int		z_flag;
}				t_flag;

t_flag			flag_analazer(const char *s);
void			print_flags(t_flag flags);
char			*redactor(char *arg, t_flag flags, int isdigit);
char			*specifier(char ch, t_flag flags, va_list *ap);

#endif
