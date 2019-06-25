/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 18:27:57 by vinograd          #+#    #+#             */
/*   Updated: 2019/06/24 19:24:53 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ftoa(float i)
{
	int		a;
	char	*str;

	a = (int)i;
	i -= a;
	while (i > (int)i)
		i *= 10;
	str = ft_strjoin(ft_strjoin(ft_itoa(a), "."), ft_itoa(i));
	return (str);
}
