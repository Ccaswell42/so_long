/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_1str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaswell <ccaswell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:19:37 by ccaswell          #+#    #+#             */
/*   Updated: 2021/11/29 17:07:03 by ccaswell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
int	print_1str(const char *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
	return (ft_strlen(s));
}
