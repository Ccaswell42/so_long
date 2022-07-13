/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upper_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaswell <ccaswell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:19:06 by ccaswell          #+#    #+#             */
/*   Updated: 2021/11/29 15:31:11 by ccaswell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
static char	upp_word(int z)
{
	if (z == 10)
		return ('A');
	else if (z == 11)
		return ('B');
	else if (z == 12)
		return ('C');
	else if (z == 13)
		return ('D');
	else if (z == 14)
		return ('E');
	else if (z == 15)
		return ('F');
	else
		return (z + '0');
}

int	upper_x(va_list ptr)
{
	unsigned int	a;
	int				b;
	int				cnt;
	char			str[99];

	a = va_arg(ptr, int);
	cnt = 0;
	while (a > 15)
	{
		str[cnt] = upp_word(a % 16);
		a = a / 16;
		cnt++;
	}
	b = 0;
	str[cnt] = upp_word(a);
	while (cnt >= 0)
	{
		write (1, &str[cnt], 1);
		b++;
		cnt--;
	}
	return (b);
}
