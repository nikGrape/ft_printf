/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 13:07:55 by vinograd          #+#    #+#             */
/*   Updated: 2019/06/25 01:07:29 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"
# include <stdio.h>

typedef struct	s_flags
{
	int	steps;
	int hashtag;
	int minus;
	int spase;
	int plus;
	int zero;
	int width;
	int length;
	int l_flag;
	int h_flag;
}				t_flag;

void			print_hex(int num, int form);
t_flag			flag_analazer(const char *s);
void			print_flags(t_flag flags);
char			*redactor(char *s, t_flag flags, int isdigit);
char			*ft_stradd(char *str, char ch);
char			*ft_itoa_base(int nbr, int base);
char			*specifier(char ch, t_flag flags, va_list *ap);
char			*ft_itoa_base_unsign(size_t nbr, int base);


#endif
