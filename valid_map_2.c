/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaswell <ccaswell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 18:15:25 by ccaswell          #+#    #+#             */
/*   Updated: 2022/03/16 16:04:57 by ccaswell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	valid_wall(t_mapa *mapa_main)
{
	char	**map;
	int		i;
	int		j;

	map = mapa_main->map_data;
	j = 0;
	i = 0;
	while (i < ((mapa_main->length) - 1))
	{
		if (map[0][i] != '1')
			massage_error("map not closed");
		i++;
	}
	i = 0;
	j = ((mapa_main->height) - 1);
	while (i < ((mapa_main->length) - 1))
	{
		if (map[j][i] != '1')
			massage_error("map not closed");
		i++;
	}
	valid_wall2(mapa_main);
}

void	valid_wall2(t_mapa *mapa_main)
{
	char	**map;
	int		j;
	int		l;

	map = mapa_main->map_data;
	l = ((mapa_main->length) - 2);
	j = 0;
	while (j < (mapa_main->height))
	{
		if (map[j][0] != '1')
			massage_error("map not closed");
		if (map[j][l] != '1')
			massage_error("map not closed");
		j++;
	}
}

void	find_player(t_mapa *mapa_main)
{
	char	**map;
	int		i;
	int		j;

	map = mapa_main->map_data;
	j = 0;
	while (j < (mapa_main->height))
	{
		i = 0;
		while (map[j][i])
		{
			if ((map[j][i]) == 'P')
			{
				mapa_main->column_p = j;
				mapa_main->line_p = i;
			}
			i++;
		}
		j++;
	}
}

void	all_validation(char *str, t_mapa *map_main)
{
	valid_name(str);
	ft_rectangle(map_main);
	components(map_main, 0, 0);
	other_characters(map_main);
	valid_wall(map_main);
	find_player(map_main);
}
