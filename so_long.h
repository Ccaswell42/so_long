/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaswell <ccaswell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:46:20 by ccaswell          #+#    #+#             */
/*   Updated: 2022/03/09 18:18:13 by ccaswell         ###   ########.fr       */
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



#endif