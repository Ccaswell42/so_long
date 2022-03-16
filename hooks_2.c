/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaswell <ccaswell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:35:38 by ccaswell          #+#    #+#             */
/*   Updated: 2022/03/16 16:40:06 by ccaswell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	down_mv(t_data *data, char **karta, int column, int line)
{
	if (karta[column + 1][line] != '1')
	{
		if (karta[column][line] == 'E')
			karta[column][line] = 'E';
		else
			karta[column][line] = '0';
		if (karta[column + 1][line] == 'E')
		{
			data->m->map_data = karta;
			data->m->column_p = (column + 1);
			e_otrisovka(data, 0);
		}
		else
		{
			karta[column + 1][line] = 'P';
			data->m->map_data = karta;
			data->m->column_p = (column + 1);
			otrisovochka(data);
		}
		data->move_number++;
		ft_printf("Number of movements: %d\n", data->move_number);
	}
}

int	key_hook(int key_code, t_data *data)
{
	char	**karta;
	int		column;
	int		line;

	karta = data->m->map_data;
	column = data->m->column_p;
	line = data->m->line_p;
	if (key_code == 13)
		up_mv(data, karta, column, line);
	else if (key_code == 53)
		exit_hook();
	else if (key_code == 2)
		right_mv(data, karta, column, line);
	else if (key_code == 0)
		left_mv(data, karta, column, line);
	else if (key_code == 1)
		down_mv(data, karta, column, line);
	return (0);
}
