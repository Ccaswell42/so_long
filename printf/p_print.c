/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_print.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaswell <ccaswell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:19:32 by ccaswell          #+#    #+#             */
/*   Updated: 2021/11/29 15:27:40 by ccaswell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	words(int z)
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

static int	ft_print_pointer(unsigned long long a)
{
	int		b;
	int		cnt;
	char	str[99];

	cnt = 0;
	while (a > 15)
	{
		str[cnt] = words(a % 16);
		a = a / 16;
		cnt++;
	}
	b = 0;
	str[cnt] = words(a);
	while (cnt >= 0)
	{
		write (1, &str[cnt], 1);
		b++;
		cnt--;
	}
	return (b);
}

int	p_print(va_list ptr)
{
	unsigned long long	p;

	p = (unsigned long long)va_arg(ptr, void *);
	if (!p)
	{
		ft_putstr_fd("0x0", 1);
		return (3);
	}
	else
	{
		ft_putstr_fd("0x", 1);
		return (ft_print_pointer(p) + 2);
	}
}
