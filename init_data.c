/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaswell <ccaswell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 12:46:35 by ccaswell          #+#    #+#             */
/*   Updated: 2022/03/16 15:59:07 by ccaswell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	massage_error(char *str)
{
	write(2, "Error\n", 6);
	ft_printf("%s\n", str);
	exit(1);
}

t_data	*init_data(t_mapa *m, t_render *r, t_texture *t)
{
	t_data	*d;

	d = malloc(sizeof(t_data));
	if (!d)
		ft_error();
	d->m = m;
	d->r = r;
	d->t = t;
	d->move_number = 0;
	return (d);
}
