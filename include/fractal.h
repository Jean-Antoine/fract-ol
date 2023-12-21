/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 13:32:29 by jeada-si          #+#    #+#             */
/*   Updated: 2023/12/21 11:01:23 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H
# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# define MAX_ITER 300

typedef struct s_pxl
{
	int				x;
	int				y;
	float			r;
	float			i;
	int				color;
	struct s_pxl	*next;
}				t_pxl;

typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef t_pxl	t_cmplx;
t_pxl	*ft_new_node(int x, int y, float r, float i);
t_pxl	*ft_get_grid(t_cmplx center, int zoom, int width, int height);
void	ft_clear_grid(t_pxl *grid);   
t_pxl	*ft_julia_grid(t_pxl *grid, t_cmplx c);
t_pxl	*ft_mandelbrot_grid(t_pxl *grid);
void	ft_grid_to_img(t_pxl *grid, t_img *img);
void	ft_clear_grid(t_pxl *grid);
int		ft_key_hook(int keycode, void *param);

#endif