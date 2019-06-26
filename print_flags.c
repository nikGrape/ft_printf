/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 15:41:44 by vinograd          #+#    #+#             */
/*   Updated: 2019/06/25 16:15:54 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

	// int	steps; +
	// int hashtag;+
	// int minus; +
	// int spase;+
	// int plus;+
	// int zero; +
	// int width; 
	// int length; 
	// int l_flag;
	// int h_flag;

void print_flags(t_flag flags)
{
	printf("steps\t%d\nhashtag\t%d\n", flags.steps, flags.hashtag);
	printf("minus\t%d\nspase\t%d\n", flags.minus, flags.spase);
	printf("plus\t%d\nzero\t%d\n", flags.plus, flags.zero);
	printf("width\t%d\nwidth\t%d\n", flags.width, flags.length);
	printf("l_flag\t%d\nh_flag\t%d\n", flags.l_flag, flags.h_flag);
}
