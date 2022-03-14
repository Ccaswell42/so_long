HEAD = so_long.h 
NAME = so_long
LIBFT = libft/libft.a
FLAGS = -Wall -Wextra -Werror -Imlx 

SRCS = gnl_main.c get_next_line.c utils.c valid_map.c valid_map_2.c hooks.c init_data.c
OBJS = $(SRCS:.c=.o)
MLX	= -Lmlx -lmlx -framework OpenGL -framework AppKit

.PHONY: all bonus clean fclean re

all: $(NAME)

$(NAME): $(OBJS) $(HEAD) $(LIBFT)
		make -s -C ./mlx
		cc -o so_long $(OBJS) $(MLX) -L./libft -lft

$(LIBFT):
		$(MAKE) -C ./libft
		

%.o:	%.c $(HEAD)
			cc $(FLAGS) -Imlx -c $< -o $@

clean:
	$(MAKE) clean -C ./libft
	rm -rf $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)
	
re: fclean all
