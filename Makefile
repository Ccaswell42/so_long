HEAD = so_long.h 
NAME = so_long
LIBFT = libft/libft.a
FLAGS = -Wall -Wextra -Werror -Imlx

SRCS = main.c 
OBJS = $(SRCS:.c=.o)

.PHONY: all bonus clean fclean re

all: $(NAME)

$(NAME): $(OBJS) $(HEAD) $(LIBFT)
		cc -o so_long $(OBJS) -lmlx -lmlx -framework OpenGL -framework AppKit -L./libft -lft

$(LIBFT):
		$(MAKE) -C ./libft
		

%.o:	%.c $(HEAD)
			cc $(FLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C ./libft
	rm -rf $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)
	
re: fclean all
