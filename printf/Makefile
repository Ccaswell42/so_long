SRCS = c_print.c \
	i_d_print.c \
	lower_x.c \
	p_print.c \
	s_print.c \
	u_print.c \
	upper_x.c \
	print_1str.c \
	percent_print.c \
	print_for_type.c \
	ft_printf.c \
	

HEAD = ft_printf.h
NAME = libftprintf.a
LIBFT = libft/libft.a
OBJS = $(SRCS:.c=.o)
FLAGS = -Wall -Wextra -Werror

.PHONY: all bonus clean fclean re

$(NAME): $(OBJS)
			$(MAKE) -C ./libft
			cp $(LIBFT) $(NAME)
			ar rc $(NAME) $(OBJS)

%.o:	%.c $(HEAD)
			gcc $(FLAGS) -c $< -o $@

all: $(NAME)

clean:
	$(MAKE) clean -C ./libft
	rm -f $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME)

re: fclean all
