/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 09:43:00 by exam              #+#    #+#             */
/*   Updated: 2019/06/22 15:37:10 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <wchar.h>

void	convert(size_t i, int form)
{
	char nums[] = "0123456789abcdef";
	char nums2[] = "0123456789ABCDEF";

	if (form)
		write(1, &nums2[i], 1);
	else
		write(1, &nums[i], 1);
}

void	print_hex(size_t i, int form)
{
	if (i >= 16)
		print_hex(i / 16, form);
	convert(i % 16, form);
}
