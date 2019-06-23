/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_to_function.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 19:44:06 by vinograd          #+#    #+#             */
/*   Updated: 2019/06/20 19:47:21 by vinograd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int func1(int i)
{
	return (i * 2);
}

int func2(int i)
{
	return (i * 5);
}

#include <stdio.h>

int main()
{
	int (*f)(int);
	int i;

	f = &func2;
	i = f(5);
	printf("%d\n", i);
}