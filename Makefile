HEAD = so_long.h 
NAME = so_long
LIBFT = ./printf/libft/libft.a
PRINTF = ./printf/libftprintf.a
FLAGS = -Wall -Wextra -Werror -Imlx 

SRCS = gnl_main.c get_next_line.c utils.c valid_map.c valid_map_2.c hooks.c init_data.c \
		win_game_hooks.c image.c hooks_2.c
OBJS = $(SRCS:.c=.o)
MLX	= -Lmlx -lmlx -framework OpenGL -framework AppKit

.PHONY: all bonus clean fclean re

all: $(NAME)

$(NAME): $(OBJS) $(HEAD) $(PRINTF)
		make -s -C ./mlx
		cc -o $(NAME) $(OBJS) $(MLX) $(PRINTF)

$(PRINTF) :
		$(MAKE) -C ./printf	

%.o:	%.c $(HEAD)
			cc $(FLAGS) -Imlx  -c $< -o $@

clean:
	$(MAKE) clean -C ./printf/libft
	$(MAKE) clean -C ./printf
	rm -rf $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./printf/libft
	$(MAKE) fclean -C ./printf
	rm -rf $(NAME)
	
re: fclean all
