/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaswell <ccaswell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:47:07 by ccaswell          #+#    #+#             */
/*   Updated: 2022/03/15 13:40:15 by ccaswell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

t_render *init_render(t_mapa *mapa_main)
{
	t_render *x;
	
	x = malloc(sizeof(t_render));
	if (!x)
		ft_error();
	x->mlx = mlx_init();
	int a = mapa_main->length;
	a--;
	int v = mapa_main->height;
	x->win = mlx_new_window((x->mlx), 32 * a, v * 32, "Hello world!");
	return (x);
}

t_texture *testures(t_render *tmp)
{
	t_texture *imgs;
	int		img_width;
	int		img_height;
	
	imgs = malloc(sizeof(t_texture));
	if (!imgs)
		ft_error();
	imgs->collect = mlx_xpm_file_to_image(tmp->mlx, "./assets/collect.xpm", &img_width, &img_height);
	imgs->exit = mlx_xpm_file_to_image(tmp->mlx, "./assets/exit.xpm", &img_width, &img_height);
	imgs->free = mlx_xpm_file_to_image(tmp->mlx, "./assets/free.xpm", &img_width, &img_height);
	imgs->wals = mlx_xpm_file_to_image(tmp->mlx, "./assets/wals.xpm", &img_width, &img_height);
	imgs->zombu = mlx_xpm_file_to_image(tmp->mlx, "./assets/zombu.xpm", &img_width, &img_height);
	return (imgs);
}

void otrisovochka(t_mapa *mapa_main , t_render *tmp, t_texture *imgs)
{
	int i;
	int x;
	int	y;
	int j;
	char **str;
	
	x = 0;
	y = 0;
	str = mapa_main->map_data;
	j = 0;
	
	while (str[j])
	{
		i = 0;
		y = 0;
		while (i < (mapa_main->length))
		{
			if (str[j][i] == '1')
			{
				mlx_put_image_to_window(tmp->mlx, tmp->win, imgs->wals, y, x);
				y +=32;
			}
			else if (str[j][i] == '0')
			{
				mlx_put_image_to_window(tmp->mlx, tmp->win, imgs->free, y, x);
				y +=32;
			}
			else if (str[j][i] == 'C')
			{
				mlx_put_image_to_window(tmp->mlx, tmp->win, imgs->collect, y, x);
				y +=32;
			}
			else if (str[j][i] == 'P')
			{
				mlx_put_image_to_window(tmp->mlx, tmp->win, imgs->free, y, x);
				mlx_put_image_to_window(tmp->mlx, tmp->win, imgs->zombu, y, x);
				y +=32;
			}
			else if (str[j][i] == 'E')
			{
				mlx_put_image_to_window(tmp->mlx, tmp->win, imgs->free, y, x);
				mlx_put_image_to_window(tmp->mlx, tmp->win, imgs->exit, y, x);
				y +=32;
			}
			i++;
		}
		j++;
		x += 32;
		
	}	
}
