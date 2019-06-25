/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 15:41:44 by vinograd          #+#    #+#             */
/*   Updated: 2019/06/24 19:59:39 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

	// int minus;
	// int zero;
	// int spase;
	// int lehgth;
	// int width;
	// int l_flag;
	// int h_flag;

void print_flags(t_flag flags)
{
	printf("steps %d\n- %d\n0 %d\nspase %d\n", flags.steps, flags.minus, flags.zero, flags.spase);
	printf("len %d\nwidth %d\nl %d\nh %d\n", flags.length, flags.width, flags.l_flag, flags.h_flag);
}
