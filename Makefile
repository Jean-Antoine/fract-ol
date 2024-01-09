SRCS_D				= ./srcs/
HEADER_D			= ./include/
SRCS_F				= ft_new_pxl.c\
						ft_pxl_to_cmplx.c \
						ft_init_grid.c \
						ft_update_grid.c\
						ft_clear_grid.c\
						ft_julia_grid.c\
						ft_mandelbrot_grid.c\
						ft_burningship_grid.c\
						ft_grid_to_img.c \
						ft_clear_img.c \
						ft_key_hook.c \
						ft_expose_hook.c \
						ft_mouse_hook.c \
						ft_update_window.c \
						ft_close_window.c \
						ft_home_view.c \
						ft_read_params.c
SRCS 				= $(addprefix $(SRCS_D), $(SRCS_F))
LIB_MLX_D			= ./mlx/
LIBFT_D				= ./libft/
NAME 				= fractol
CFLAGS 				= -Wall -Wextra -Werror
CPPFLAGS 			= -I$(HEADER_D) -I$(LIB_MLX_D) -I$(LIBFT_D)/include
CC 					= cc

all: $(NAME)

mlx :
	if [ ! -d $(LIB_MLX_D) ]; then git clone https://github.com/42Paris/minilibx-linux.git $(LIB_MLX_D); fi;
	make -C $(LIB_MLX_D)

libft:
	make -C $(LIBFT_D)

$(NAME): main.c $(SRCS) mlx libft
	cc $(CFLAGS) $(CPPFLAGS) main.c -o $(NAME) $(SRCS) -L$(LIB_MLX_D) -L$(LIBFT_D) -lmlx -lX11 -lXext -lft

debug: main.c $(SRCS)
	cc $(CFLAGS) $(CPPFLAGS) -g main.c -o debug $(SRCS) -L$(LIB_MLX_D) -lmlx -lX11 -lXext

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) debug

re: fclean all

test: re
	./$(NAME)

norme:
	norminette $(SRCS) main.c
	norminette -R CheckDefine $(HEADER_D)*.h

.PHONY: clean fclean re mlx all test norme libft
