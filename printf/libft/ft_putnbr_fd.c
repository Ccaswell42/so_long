/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaswell <ccaswell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 13:27:35 by ccaswell          #+#    #+#             */
/*   Updated: 2021/10/26 16:22:28 by ccaswell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	n_abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	a;

	if (n == -2147483648)
	{
		write (fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
		ft_putchar_fd('-', fd);
	if (n_abs(n) < 10)
	{
		a = n_abs(n) + '0';
		ft_putchar_fd(a, fd);
	}
	else
	{
		ft_putnbr_fd(n_abs(n / 10), fd);
		a = n_abs(n % 10) + '0';
		ft_putchar_fd(a, fd);
	}
}
