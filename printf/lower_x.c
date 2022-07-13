/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lower_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaswell <ccaswell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:19:29 by ccaswell          #+#    #+#             */
/*   Updated: 2021/11/29 15:23:30 by ccaswell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
static char	low_word(int z)
{
	if (z == 10)
		return ('a');
	else if (z == 11)
		return ('b');
	else if (z == 12)
		return ('c');
	else if (z == 13)
		return ('d');
	else if (z == 14)
		return ('e');
	else if (z == 15)
		return ('f');
	else
		return (z + '0');
}

int	lower_x(va_list ptr)
{
	unsigned int	a;
	int				b;
	int				cnt;
	char			str[99];

	a = va_arg(ptr, int);
	cnt = 0;
	while (a > 15)
	{
		str[cnt] = low_word(a % 16);
		a = a / 16;
		cnt++;
	}
	b = 0;
	str[cnt] = low_word(a);
	while (cnt >= 0)
	{
		write (1, &str[cnt], 1);
		b++;
		cnt--;
	}
	return (b);
}
