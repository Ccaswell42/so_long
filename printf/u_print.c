/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_print.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaswell <ccaswell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:19:42 by ccaswell          #+#    #+#             */
/*   Updated: 2021/11/29 15:29:52 by ccaswell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr_fd_un(unsigned int n, int fd)
{
	char	a;

	if (n < 10)
	{
		a = n + '0';
		ft_putchar_fd(a, fd);
	}
	else
	{
		ft_putnbr_fd(n / 10, fd);
		a = n % 10 + '0';
		ft_putchar_fd(a, fd);
	}
}

int	u_print(va_list ptr)
{
	unsigned int	a;
	int				x;

	x = 1;
	a = va_arg(ptr, unsigned int);
	ft_putnbr_fd_un(a, 1);
	if (a < 10)
		return (x);
	while (a >= 10)
	{
		a = a / 10;
		x++;
	}
	return (x);
}
