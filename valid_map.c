/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaswell <ccaswell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:48:21 by ccaswell          #+#    #+#             */
/*   Updated: 2022/03/16 16:12:27 by ccaswell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_rectangle(t_mapa *mapa_main)
{
	char	**map;
	int		i;
	int		len;

	i = 1;
	map = mapa_main->map_data;
	len = ft_strlen(map[0]);
	mapa_main->length = len;
	len = 0;
	while (i < (mapa_main->height))
	{
		len = ft_strlen(map[i]);
		if (i == (mapa_main->height - 1))
			len += 1;
		if (len != mapa_main->length)
			massage_error("map isn't rectangular");
		i++;
	}
	mapa_main->collect = 0;
	mapa_main->current_collect = 0;
}

void	components(t_mapa *mapa_main, int p, int e)
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
				p += 1;
			if ((map[j][i]) == 'E')
				e += 1;
			if ((map[j][i]) == 'C')
				(mapa_main->collect) += 1;
			i++;
		}
		j++;
	}
	if ((p != 1) || (e < 1) || ((mapa_main->collect) < 1))
		massage_error("components error");
}

void	other_characters(t_mapa *mapa_main)
{
	char	**map;
	int		i;
	int		j;

	map = mapa_main->map_data;
	j = 0;
	while (j < (mapa_main->height))
	{
		i = 0;
		while ((map[j][i] == '1') || (map[j][i] == 'C') || (map[j][i] == 'E') \
		|| (map[j][i] == 'P') || (map[j][i] == '0'))
			i++;
		if (i != ((mapa_main->length) - 1))
			massage_error("extra components");
		j++;
	}
}

void	valid_name(char *s)
{
	int	i;

	i = ft_strlen(s);
	i -= 1;
	if ((s[i] == 'r') && (s[i - 1] == 'e') && \
	(s[i - 2] == 'b') && (s[i - 3] == '.'))
		i = 0;
	else
		massage_error("invald name");
}
