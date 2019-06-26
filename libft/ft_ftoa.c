/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 18:27:57 by vinograd          #+#    #+#             */
/*   Updated: 2019/06/26 01:46:31 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ftoa(double i, int precision)
{
	int		a;
	char	*str;

	a = (int)i;
	i -= a;
	while (i > (int)i && precision--)
		i *= 10;
	str = ft_strjoin_free(ft_strjoin_free(ft_itoa(a), ".", 1), ft_itoa(i), 3);
	return (str);
}
