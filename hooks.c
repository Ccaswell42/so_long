#include "so_long.h"

int exit_hook(void)
{
    exit (0);
    return (0);
}

void up_mv(t_data *data)
{
	char **karta;
	int column;
	int line;

    karta = data->m->map_data;
	column = data->m->column_p;
	line = data->m->line_p;
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
			e_otrisovka(data->m , data->r, data->t);
		}
		else 
		{
			karta[column - 1][line] = 'P';
			data->m->map_data = karta;
			data->m->column_p = (column - 1);
			otrisovochka(data->m , data->r, data->t);
		}
		data->move_number++;
		ft_printf("Number of movements: %d\n", data->move_number);
	}
}

void right_mv(t_data *data)
{
	char **karta;
	int column;
	int line;

    karta = data->m->map_data;
	column = data->m->column_p;
	line = data->m->line_p;
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
			e_otrisovka(data->m , data->r, data->t);
		}
		else 
		{
			karta[column][line + 1] = 'P';
			data->m->map_data = karta;
			data->m->line_p = (line + 1);
			otrisovochka(data->m , data->r, data->t);
		}
		data->move_number++;
		ft_printf("Number of movements: %d\n", data->move_number);
	}
}

void left_mv(t_data *data)
{
	char **karta;
	int column;
	int line;

    karta = data->m->map_data;
	column = data->m->column_p;
	line = data->m->line_p;
	if (karta[column][line - 1] != '1')
	{
		if (karta[column][line] == 'E')
			karta[column][line] = 'E';
		else 
			karta[column][line] = '0';
		if (karta[column][line - 1] == 'E')
		{	data->m->map_data = karta;
			data->m->line_p = (line - 1);
			e_otrisovka(data->m , data->r, data->t);
		}
		else 
		{
			karta[column][line - 1] = 'P';
			data->m->map_data = karta;
			data->m->line_p = (line - 1);
			otrisovochka(data->m , data->r, data->t);
		}
		data->move_number++;
		ft_printf("Number of movements: %d\n", data->move_number);
	}
}

void down_mv(t_data *data)
{
	char **karta;
	int column;
	int line;

    karta = data->m->map_data;
	column = data->m->column_p;
	line = data->m->line_p;
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
			e_otrisovka(data->m , data->r, data->t);
		}
		else 
		{
			karta[column + 1][line] = 'P';
			data->m->map_data = karta;
			data->m->column_p = (column + 1);
			otrisovochka(data->m , data->r, data->t);
		}
		data->move_number++;
		ft_printf("Number of movements: %d\n", data->move_number);
	}

}

int key_hook(int key_code, t_data *data)
{
	if (key_code == 13)
		up_mv(data);
	else if (key_code == 53)
		exit_hook();
	else if (key_code == 2)
		right_mv(data);
	else if (key_code == 0)
		left_mv(data);
	else if (key_code == 1)
		down_mv(data);

    return (0);
}