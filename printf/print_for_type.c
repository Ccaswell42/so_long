/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_for_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaswell <ccaswell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:53:13 by ccaswell          #+#    #+#             */
/*   Updated: 2021/11/29 17:03:57 by ccaswell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
int	print_for_type(va_list ptr, char x)
{
	if ((x == 'i') || (x == 'd'))
		return (i_d_print(ptr));
	else if (x == 's')
		return (s_print(ptr));
	else if (x == 'c')
		return (c_print(ptr));
	else if (x == '%')
		return (percent_print('%'));
	else if (x == 'u')
		return (u_print(ptr));
	else if (x == 'x')
		return (lower_x(ptr));
	else if (x == 'X')
		return (upper_x(ptr));
	else if (x == 'p')
		return (p_print(ptr));
	return (0);
}
