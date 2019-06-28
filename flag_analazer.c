/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_analazer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 17:05:39 by vinograd          #+#    #+#             */
/*   Updated: 2019/06/27 17:52:50 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

	// int	steps; +
	// int hashtag;+
	// int minus; +
	// int spase;+
	// int plus;+
	// int zero; +
	// int width; +
	// int length; +
	// int l_flag;
	// int h_flag;

int		is_flag(char ch)
{
	if (ch == ' ' || ch == '#' || ch == '+' || ch == '-')
		return (1);
	return (0);
}

// t_flag	flag_analazer2(const char *s)
// {
// 	while ()
// }

t_flag	flag_analazer(const char *s)
{
	t_flag flags;

	ft_bzero(&flags, sizeof(t_flag));
	flags.width = -1;
	while (s[flags.steps] == '#')
	{
		flags.hashtag = 1;
		flags.steps++;
	}
	if (s[flags.steps] == '-')
	{
		flags.minus = 1;
		flags.steps++;
	}
	while (s[flags.steps] == ' ')
	{
		flags.spase = 1;
		flags.steps++;
	}
	while (s[flags.steps] == '+')
	{
		flags.plus = 1;
		flags.steps++;
	}
	while (s[flags.steps] == ' ')
	{
		flags.spase = 1;
		flags.steps++;
	}
	while (s[flags.steps] == '0')
	{
		flags.zero = 1;
		flags.steps++;
	}
	if (s[flags.steps] >= '1' && s[flags.steps] <= '9')
	{
		flags.length = ft_atoi(&s[flags.steps]);
		while (s[flags.steps] >= '0' && s[flags.steps] <= '9')
			flags.steps++;
	}
	if (s[flags.steps] == '.')
	{
		flags.width = ft_atoi(&s[++flags.steps]);
		while (s[flags.steps] >= '0' && s[flags.steps] <= '9')
			flags.steps++;
	}
	while (s[flags.steps] == 'l')
	{
		flags.l_flag++;
		flags.steps++;
	}
	while (s[flags.steps] == 'h')
	{
		flags.h_flag++;
		flags.steps++;
	}
	if (s[flags.steps] == 'j')
	{
		flags.j_flag++;
		flags.steps++;
	}
	if (flags.minus)
		flags.zero = 0;
	return (flags);
}
