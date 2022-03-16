/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaswell <ccaswell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:12:45 by ccaswell          #+#    #+#             */
/*   Updated: 2022/03/16 16:45:46 by ccaswell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_mapa	*amount(char *argv)
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

t_mapa	*read_map(char *argv)
{
	int		fd;
	char	**map;
	int		j;
	t_mapa	*map_main;

	fd = open(argv, O_RDONLY);
	map_main = amount(argv);
	j = map_main->height;
	map = malloc(sizeof(char *) * (j + 1));
	if (!map)
		ft_error();
	j = 0;
	while (1)
	{
		map[j] = get_next_line(fd);
		if (!map[j])
			break ;
		j++;
	}
	map_main->map_data = map;
	close (fd);
	return (map_main);
}

int	main(int argc, char **argv)
{
	t_mapa		*map_main;
	t_render	*tmp;
	t_texture	*imgs;
	t_data		*data;

	if (argc < 2)
		exit (0);
	map_main = read_map(argv[1]);
	all_validation(argv[1], map_main);
	tmp = init_render(map_main);
	imgs = testures(tmp);
	data = init_data(map_main, tmp, imgs);
	otrisovochka(data);
	mlx_hook(tmp->win, 17, 0, exit_hook, data);
	mlx_loop_hook(tmp->mlx, game_win_hook, data);
	mlx_key_hook(tmp->win, key_hook, data);
	mlx_loop(tmp->mlx);
	exit (0);
}
