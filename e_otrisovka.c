#include "so_long.h"
void e_otrisovka(t_mapa *mapa_main , t_render *tmp, t_texture *imgs)
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
				if ((mapa_main->column_p == j ) && (mapa_main->line_p == i))
					mlx_put_image_to_window(tmp->mlx, tmp->win, imgs->zombu, y, x);
				y +=32;
			}
			i++;
		}
		j++;
		x += 32;
		
	}	
}