/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaswell <ccaswell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 16:17:58 by ccaswell          #+#    #+#             */
/*   Updated: 2021/10/23 13:16:07 by ccaswell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_rev(char *str)
{
	int		i;
	int		a;
	int		g;
	char	c;

	i = 0;
	a = 0;
	while (str[a])
		a++;
	g = a;
	a--;
	while (i < (g / 2))
	{
		c = str[i];
		str[i] = str[a];
		str[a] = c;
		a--;
		i++;
	}
}

static int	ft_countd(int n)
{
	int	x;

	x = 1;
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

static int	n_abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		i;
	int		a;

	i = 0;
	a = n;
	s = ft_calloc((ft_countd(n) + 1), sizeof(char));
	if (!s)
		return (0);
	if (n == 0)
		s[0] = '0';
	while (n != 0)
	{
		s[i] = '0' + (n_abs(n % 10));
		n = n / 10;
		i++;
	}
	if (a < 0)
		s[i] = '-';
	ft_rev(s);
	return (s);
}
