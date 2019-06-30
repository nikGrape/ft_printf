/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 18:27:57 by vinograd          #+#    #+#             */
/*   Updated: 2019/06/29 19:17:04 by vinograd         ###   ########.fr       */
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

char		*ft_ftoa(double i, int precision)
{
	int		a;
	char	*str;

	a = (int)i;
	i -= a;
	while (i > (int)i && precision--)
		i *= 10;
	i += approximator(i);
	str = ft_strjoin_free(ft_strjoin_free(ft_itoa(a), ".", 1), ft_itoa(i), 3);
	return (str);
}

char		*ft_ftoa_long(long double i, int precision)
{
	int		a;
	char	*str;

	a = (int)i;
	i -= a;
	while (i > (int)i && precision--)
		i *= 10;
	i += approximator((double)i);
	str = ft_strjoin_free(ft_strjoin_free(ft_itoa(a), ".", 1), ft_itoa(i), 3);
	return (str);
}
