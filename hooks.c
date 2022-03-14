#include "so_long.h"

int exit_hook(void)
{
    exit (0);
    return (0);
}

int press_Z(t_mapa *main_mapa)
{
    char **karta;
    karta = main_mapa->map_data;
    karta[4][1] = '0';
    karta[3][3] = 'P';
    main_mapa->map_data = karta;
    return (0);
}

int key_hook(int key_code, t_data *data)
{
    char **karta;

    karta = data->m->map_data;
    if (key_code == 1)
    {
        karta[3][1] = '0';
        karta[4][1] = 'P';
        data->m->map_data = karta;
        otrisovochka(data->m , data->r, data->t);
    }
    //s
    return (0);
}