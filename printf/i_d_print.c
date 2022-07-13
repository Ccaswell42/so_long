/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_d_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaswell <ccaswell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:19:26 by ccaswell          #+#    #+#             */
/*   Updated: 2021/11/29 15:21:54 by ccaswell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
int	i_d_print(va_list ptr)
{
	int	x;
	int	n;

	x = 1;
	n = va_arg(ptr, int);
	ft_putnbr_fd(n, 1);
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n = -n;
		x++;
	}
	if (n < 10)
		return (x);
	while (n >= 10)
	{
		n = n / 10;
		x++;
	}
	return (x);
}
