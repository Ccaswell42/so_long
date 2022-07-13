/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaswell <ccaswell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:19:23 by ccaswell          #+#    #+#             */
/*   Updated: 2021/11/29 17:12:22 by ccaswell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h> 
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

int		ft_printf(const char *str, ...);
int		s_print(va_list ptr);
int		c_print(va_list ptr);
int		i_d_print(va_list ptr);
int		u_print(va_list ptr);
int		lower_x(va_list ptr);
int		upper_x(va_list ptr);
int		p_print(va_list ptr);
int		print_1str(const char *s, int fd);
int		percent_print(char x);
int		print_for_type(va_list ptr, char x);

#endif