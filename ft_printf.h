/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 13:07:55 by vinograd          #+#    #+#             */
/*   Updated: 2019/06/22 17:52:33 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

typedef struct	s_flags
{
	int minus;
	int zero;
	int spase;
	int width;
	int lehgth;
	int l_flag;
	int h_flag;
}				t_flag;

void			print_hex(int num, int form);
t_flag			flag_analazer(char *s);

#endif
