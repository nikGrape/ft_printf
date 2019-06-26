/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 15:28:12 by vinograd          #+#    #+#             */
/*   Updated: 2019/06/25 15:45:07 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	size(unsigned int i)
{
	int size;

	if (i == 0)
		return (1);
	size = 0;
	while (i > 0)
	{
		i /= 10;
		size++;
	}
	return (size);
}

char		*ft_itoa_unsigned(unsigned int nbr)
{
	char	*str;
	int		len;

	len = size(nbr);
	if (!(str = ft_strnew(len)))
		return (NULL);
	while (len-- >= 0)
	{
		str[len] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (str);
}
