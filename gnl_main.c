/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaswell <ccaswell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:12:45 by ccaswell          #+#    #+#             */
/*   Updated: 2022/03/11 14:06:15 by ccaswell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



t_mapa *amount(char *argv)
{
	t_mapa	*map_main;
	char	*len;
	int		i;
	int		fd;
	
	i = 0;
	map_main = malloc(sizeof(t_mapa));
	if (!map_main)
		ft_error();
	fd = open(argv, O_RDONLY);
	while (1)
	{
		len = get_next_line(fd);
		if (!len)
			break ;
		free (len);
		i++;
	}
	close (fd);
	map_main->height = i;
	return (map_main);
}


t_mapa *read_map(char *argv)
{
	int		fd;
	char	**map;
	int		j;
	t_mapa	*map_main;
	
	fd = open(argv, O_RDONLY);
	map_main = amount(argv);
	j = map_main->height;
	map = malloc(sizeof(char *) * (j + 1));
	j = 0;
	while (1)
	{
		map[j] = get_next_line(fd);
		if (!map[j])
			break ;
		j++;
	}
	map_main->map_data = map;
	return (map_main);
}

// /////
// void otrisovka(t_mapa *mapa_main)
// {
// 	char **map;
// 	map = mapa_main->map_data;

// 	void	*mlx;
// 	void	*img;
// 	char	*relative_path = "./wals.xpm";
// 	int		img_width;
// 	int		img_height;
// 	void	*win;

// 	mlx = mlx_init();
// 	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
// 	int a = mapa_main->length;
// 	int v = mapa_main->height;
// 	win = mlx_new_window(mlx, 32 * a, v * 32, "Hello world!");

// 	int x = 0;
// 	int i = 0;
// 	int len = (mapa_main->length);
// 	while ( i < len)
// 	{
// 		mlx_put_image_to_window(mlx, win, img, x, 0);
// 		x += 32;
// 		i++;
// 	}
// 	i = 0;
// 	x = 32;
// 	len --;
// 	int j = mapa_main->height;
// 	while (i < (j - 1))
// 	{
// 		mlx_put_image_to_window(mlx, win, img, 0, x);
// 		mlx_put_image_to_window(mlx, win, img, (len * 32), x);
// 		x +=32;
// 		i++;	
// 	}
// 	i = 0;
// 	j = mapa_main->height;
// 	x = 32;
// 	j--;
// 	while ( i < (len - 1))
// 	{
// 		mlx_put_image_to_window(mlx, win, img, x, (j * 32));
// 		x += 32;
// 		i++;
// 	}
	
// 	mlx_loop(mlx);
// }
// /////

int main(int argc, char **argv)
{
	if (argc < 2)
		exit (0);
	t_mapa *map_main;
	
	map_main = read_map(argv[1]);

	all_validation(argv[1], map_main);
	t_render *tmp = init_render(map_main);
	t_texture *imgs = testures(tmp);
	otrisovochka(map_main, tmp, imgs);
	mlx_loop(tmp->mlx);
	

	exit (0);
}