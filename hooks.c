/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaswell <ccaswell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:34:12 by ccaswell          #+#    #+#             */
/*   Updated: 2022/03/16 16:40:09 by ccaswell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_hook(void)
{
	exit (0);
	return (0);
}

void	up_mv(t_data *data, char **karta, int column, int line)
{
	if (karta[column - 1][line] != '1')
	{
		if (karta[column][line] == 'E')
			karta[column][line] = 'E';
		else
			karta[column][line] = '0';
		if (karta[column - 1][line] == 'E')
		{
			data->m->map_data = karta;
			data->m->column_p = (column - 1);
			e_otrisovka(data, 0);
		}
		else
		{
			karta[column - 1][line] = 'P';
			data->m->map_data = karta;
			data->m->column_p = (column - 1);
			otrisovochka(data);
		}
		data->move_number++;
		ft_printf("Number of movements: %d\n", data->move_number);
	}
}

void	right_mv(t_data *data, char **karta, int column, int line)
{
	if (karta[column][line + 1] != '1')
	{
		if (karta[column][line] == 'E')
			karta[column][line] = 'E';
		else
			karta[column][line] = '0';
		if (karta[column][line + 1] == 'E')
		{
			data->m->map_data = karta;
			data->m->line_p = (line + 1);
			e_otrisovka(data, 0);
		}
		else
		{
			karta[column][line + 1] = 'P';
			data->m->map_data = karta;
			data->m->line_p = (line + 1);
			otrisovochka(data);
		}
		data->move_number++;
		ft_printf("Number of movements: %d\n", data->move_number);
	}
}

void	left_mv(t_data *data, char **karta, int column, int line)
{
	if (karta[column][line - 1] != '1')
	{
		if (karta[column][line] == 'E')
			karta[column][line] = 'E';
		else
			karta[column][line] = '0';
		if (karta[column][line - 1] == 'E')
		{	
			data->m->map_data = karta;
			data->m->line_p = (line - 1);
			e_otrisovka(data, 0);
		}
		else
		{
			karta[column][line - 1] = 'P';
			data->m->map_data = karta;
			data->m->line_p = (line - 1);
			otrisovochka(data);
		}
		data->move_number++;
		ft_printf("Number of movements: %d\n", data->move_number);
	}
}
