/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 13:32:29 by jeada-si          #+#    #+#             */
/*   Updated: 2024/01/09 12:49:48 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H
# include "mlx.h"
# include "libft.h"
# include "ft_printf.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# define MAX_ITER 300
# define WINDOW_WIDTH 500
# define WINDOW_HEIGHT 500
# define JULIA 1
# define MANDELBROT 2
# define BURNINGSHIP 3

typedef struct s_cmplx
{
	float	r;
	float	i;
}				t_cmplx;

typedef struct s_pxl
{
	int				x;
	int				y;
	t_cmplx			z;
	int				color;
	struct s_pxl	*next;
}				t_pxl;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_window
{
	void	*conn;
	void	*window;
	t_img	*current;
	t_img	*next;
	t_pxl	*grid;
	t_cmplx	center;
	t_cmplx	origin;
	int		zoom;
	int		type;
}				t_window;

t_pxl	*ft_new_pxl(int x, int y);
t_cmplx	ft_pxl_to_cmplx(float x, float y, t_window *window);
void	ft_init_grid(t_window *window);
void	ft_update_grid(t_window *window);
void	ft_clear_grid(t_pxl *grid);
t_pxl	*ft_julia_grid(t_pxl *grid, t_cmplx c);
t_pxl	*ft_mandelbrot_grid(t_pxl *grid);
t_pxl	*ft_burningship_grid(t_pxl *grid);
void	ft_grid_to_img(t_pxl *grid, t_img *img);
void	ft_clear_img(t_window *window, t_img *img);
void	ft_clear_grid(t_pxl *grid);
int		ft_key_hook(int keycode, void *param);
int		ft_expose_hook(void *param);
int		ft_mouse_hook(int button, int x, int y, void *param);
void	ft_update_window(t_window *window);
void	ft_home_view(t_window *window);
int		ft_close_window(t_window *window);
int		ft_read_param(int ac, char **av, t_window *window);

#endif