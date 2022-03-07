/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaswell <ccaswell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 14:59:24 by ccaswell          #+#    #+#             */
/*   Updated: 2022/02/08 16:23:08 by ccaswell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*x;
	size_t	m;

	m = count * size;
	x = malloc(m);
	if (x)
	{
		x = ft_memset(x, 0, m);
	}
	return (x);
}
