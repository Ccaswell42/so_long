/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaswell <ccaswell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:47:07 by ccaswell          #+#    #+#             */
/*   Updated: 2022/03/16 16:07:56 by ccaswell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

t_render	*init_render(t_mapa *mapa_main)
{
	t_render	*x;
	int			a;
	int			v;

	x = malloc(sizeof(t_render));
	if (!x)
		ft_error();
	x->mlx = mlx_init();
	a = mapa_main->length;
	a--;
	v = mapa_main->height;
	x->win = mlx_new_window((x->mlx), 32 * a, v * 32, "So_long");
	return (x);
}

t_texture	*testures(t_render *tmp)
{
	t_texture	*imgs;
	int			img_width;
	int			img_height;

	imgs = malloc(sizeof(t_texture));
	if (!imgs)
		ft_error();
	imgs->collect = mlx_xpm_file_to_image(tmp->mlx, \
	"./assets/collect.xpm", &img_width, &img_height);
	imgs->exit = mlx_xpm_file_to_image(tmp->mlx, \
	"./assets/exit.xpm", &img_width, &img_height);
	imgs->free = mlx_xpm_file_to_image(tmp->mlx, \
	"./assets/free.xpm", &img_width, &img_height);
	imgs->wals = mlx_xpm_file_to_image(tmp->mlx, \
	"./assets/wals.xpm", &img_width, &img_height);
	imgs->zombu = mlx_xpm_file_to_image(tmp->mlx, \
	"./assets/zombu.xpm", &img_width, &img_height);
	return (imgs);
}

void	sub_otrisovka(t_data *data, int y, int x, int c)
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

void	otrisovochka(t_data *data)
{
	int		i;
	int		x;
	int		y;
	int		j;
	char	**str;

	x = 0;
	y = 0;
	str = data->m->map_data;
	j = 0;
	while (str[j])
	{
		i = 0;
		y = 0;
		while (i < (data->m->length))
		{
			sub_otrisovka(data, y, x, str[j][i]);
			i++;
			y += 32;
		}
		j++;
		x += 32;
	}	
}
