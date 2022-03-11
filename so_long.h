/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaswell <ccaswell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:46:20 by ccaswell          #+#    #+#             */
/*   Updated: 2022/03/11 13:40:59 by ccaswell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H



# include <unistd.h>
# include "libft/libft.h"
# include <stdio.h> 
# include <mlx.h>
# include <fcntl.h>
# include <stdlib.h>


typedef struct s_mapa
{
	int height;
	int length;
	int collect;
	int current_collect;
	char **map_data;
}	t_mapa;

typedef struct s_texture
{
	void	*collect;
	void	*free;
	void	*wals;
	void	*zombu;
	void 	*exit;
}	t_texture;

typedef struct s_render
{
	void	*mlx;
	void	*win;
	
}	t_render;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
void	ft_error(void);
t_mapa *amount(char *argv);
t_mapa *read_map(char *argv);
void ft_rectangle(t_mapa *mapa_main);
void components(t_mapa *mapa_main, int p, int e);
void other_characters(t_mapa *mapa_main);
void valid_name(char *s);
void valid_wall(t_mapa *mapa_main);
void valid_wall2(t_mapa *mapa_main);
void all_validation(char *str, t_mapa *map_main);
t_render *init_render(t_mapa *mapa_main);
t_texture *testures(t_render *tmp);
void otrisovochka(t_mapa *mapa_main , t_render *tmp, t_texture *imgs);



#endif