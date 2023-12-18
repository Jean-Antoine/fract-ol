SRCS_D				= ./srcs/
HEADER_D			= ./include/
SRCS_F				= ft_new_node.c\
						ft_get_grid.c\
						ft_clear_grid.c\
						ft_julia_grid.c\
						ft_display_grid.c
SRCS 				= $(addprefix $(SRCS_D), $(SRCS_F))
NAME 				= fractol
CFLAGS 				= -Wall -Wextra -Werror
CPPFLAGS 			= -I$(HEADER_D) -I./mlx
CC 					= cc

all: $(NAME)

$(NAME): main.c $(SRCS)
	cc $(CFLAGS) $(CPPFLAGS) main.c -o $(NAME) $(SRCS) -L./mlx -lmlx -lX11 -lXext

debug: main.c $(SRCS)
	cc $(CFLAGS) $(CPPFLAGS) -g main.c -o debug $(SRCS) -L./mlx -lmlx -lX11 -lXext

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) debug

re: fclean all

test: $(NAME)
	./$(NAME)

norme:
	norminette $(SRCS) main.c
	norminette -R CheckDefine $(HEADER_D)*.h

.PHONY: clean fclean re
