
#include "so_long.h"

int game_win_hook3(int c, t_data *data)
{
	int i;
	int j;
	char **map;

	j = 0;
	map = data->m->map_data;
	while (j < (data->m->height))
	{
		i = 0;
		while (map[j][i])
		{
			if ((map[j][i]) == 'E')
			{
				if ((data->m->column_p == j) && (data->m->line_p == i) && (c == 0))
				{
					ft_printf("You win the game with %d movents", data->move_number);
					mlx_destroy_window(data->r->mlx, data->r->win);
					exit (0);
				}
			}
			i++;
		}
		j++;
	}
	return (0);
}

int game_win_hook(t_data *data)
{
	int i;
	int j;
	int e;
	int c;
	char **map;

	map = data->m->map_data;
	i = 0;
	j = 0;
	c = 0;
	e = 0;
	while (j < (data->m->height))
	{
		i = 0;
		while (map[j][i])
		{
			if ((map[j][i]) == 'C')
				c +=1;
			i++;
		}
		j++;
	}
		return (game_win_hook3(c, data));
}
