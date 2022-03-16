/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_otrisovka.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaswell <ccaswell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 13:55:48 by ccaswell          #+#    #+#             */
/*   Updated: 2022/03/16 14:32:27 by ccaswell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sub_e_otrisovka(t_data *data, int y, int x, int c)
{
	if (c == '1')
		mlx_put_image_to_window(data->r->mlx, \
		data->r->win, data->t->wals, y, x);
	else if (c == '0')
		mlx_put_image_to_window(data->r->mlx, \
		data->r->win, data->t->free, y, x);
	else if (c == 'C')
		mlx_put_image_to_window(data->r->mlx, \
		data->r->win, data->t->collect, y, x);
	else if (c == 'P')
	{
		mlx_put_image_to_window(data->r->mlx, \
		data->r->win, data->t->free, y, x);
		mlx_put_image_to_window(data->r->mlx, \
		data->r->win, data->t->zombu, y, x);
	}
	else if (c == 'E')
	{
		mlx_put_image_to_window(data->r->mlx, \
		data->r->win, data->t->free, y, x);
		mlx_put_image_to_window(data->r->mlx, \
		data->r->win, data->t->exit, y, x);
	}
}

void	imag_exit(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->r->mlx, \
	data->r->win, data->t->free, y, x);
	mlx_put_image_to_window(data->r->mlx, \
	data->r->win, data->t->exit, y, x);
	mlx_put_image_to_window(data->r->mlx, \
	data->r->win, data->t->zombu, y, x);
}

void	e_otrisovka(t_data *data, int i)
{
	int		x;
	int		y;
	int		j;
	char	**str;

	x = 0;
	str = data->m->map_data;
	j = 0;
	while (str[j])
	{
		i = 0;
		y = 0;
		while (i < (data->m->length))
		{
			if ((str[j][i] == 'E') && (data->m->column_p == j) \
			&& (data->m->line_p == i))
				imag_exit(data, x, y);
			else
				sub_e_otrisovka(data, y, x, str[j][i]);
			i++;
			y += 32;
		}
		j++;
		x += 32;
	}	
}
