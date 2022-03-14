#include "so_long.h"

t_data *init_data(t_mapa *m, t_render *r, t_texture *t)
{
    t_data *d;
    d = malloc(sizeof(t_data));
    if (!d)
        ft_error();
    d->m = m;
    d->r = r;
    d->t = t;
    return (d);
}