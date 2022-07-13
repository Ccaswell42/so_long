/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaswell <ccaswell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:22:00 by ccaswell          #+#    #+#             */
/*   Updated: 2021/11/29 17:07:59 by ccaswell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	int		i;
	int		ret;

	ret = 0;
	i = 0;
	if (ft_strchr(str, '%') == 0)
		return (print_1str(str, 1));
	va_start(ptr, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			ret += print_for_type(ptr, str[i + 1]);
			i++;
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			ret++;
		}
		i++;
	}
	va_end(ptr);
	return (ret);
}
