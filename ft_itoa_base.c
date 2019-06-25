/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 21:23:42 by vinograd          #+#    #+#             */
/*   Updated: 2019/06/25 01:08:14 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	convert(int i)
{
	char *nums;

	nums = "0123456789abcdef";
	return (nums[i]);
}

char		*ft_itoa_base(int nbr, int base)
{
	char ch;
	char *str;

	str = NULL;
	if (nbr >= base)
		str = ft_itoa_base(nbr / base, base);
	ch = convert(nbr % base);
	return (ft_stradd(str, ch));
}

char		*ft_itoa_base_unsign(size_t nbr, int base)
{
	char ch;
	char *str;

	str = NULL;
	if (nbr >= base)
		str = ft_itoa_base_unsign(nbr / base, base);
	ch = convert(nbr % base);
	return (ft_stradd(str, ch));
}
