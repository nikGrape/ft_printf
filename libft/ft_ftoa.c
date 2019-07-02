/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 18:27:57 by vinograd          #+#    #+#             */
/*   Updated: 2019/07/01 20:32:21 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	approximator(double i)
{
	int apr;

	i *= 10;
	apr = (int)i;
	apr %= 10;
	if (apr < 5)
		return (0);
	return (1);
}

char		*ft_ftoa_long(long double i, int precision)
{
	int		a;
	int		negative;
	char	rest[500];
	int		j;

	j = 0;
	if (i < 0)
	{
		negative = 1;
		i = -i;
	}
	a = (int)i;
	i -= a;
	while (precision--)
	{
		i *= 10;
		rest[j++] = i + '0';
		i -= (int)i;
	}
	i += approximator(i);
	a = (negative) ? -a : a;
	return (ft_strjoin_free(ft_strjoin_free(ft_itoa(a), ".", 1), rest, 1));
}

char		*ft_ftoa(double i, int precision)
{
	int		a;
	char	*str;
	int		negative;
	size_t	b;
	size_t	b1;
	int k = 0;
	negative = 0;
	if (i < 0)
	{
		negative = 1;
		i = -i;
	}
	a = (int)i;
	i -= a;
	b = 0;
	b1 = 0;
	while (precision-- && k < 18)
	{
		i *= 10;
		b = b * 10 + (int)i;
		i -= (int)i;
		k++;
	}
	while (precision--)
	{
		i *= 10;
		b1 = b1 * 10 + (int)i;
		i -= (int)i;
	}
	b1 += approximator(i);
	a = (negative) ? -a : a;
	str = ft_strjoin_free(ft_itoa_unsigned(b), ft_itoa_unsigned(b1), 3);
	str = ft_strjoin_free(ft_strjoin_free(ft_itoa(a), ".", 1), str, 3);
	return (str);
}

#include <stdio.h>
int main()
{
	double d = -345.5678123456769101102020;
	char *str = ft_ftoa_long(d,50);
	printf("%s\n%.50f\n", str, d);
	double i = 543.88;
	printf("%f\n", i);
}
