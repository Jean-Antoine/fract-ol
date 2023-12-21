/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:16:13 by jeada-si          #+#    #+#             */
/*   Updated: 2023/12/21 11:36:02 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "mlx.h"
#include "fractal.h"

int	main(void)
{
	void	*conn;
	void	*window;
	t_pxl	*grid;
	t_pxl	center;
	t_pxl	origin;
	t_img	img;

	center.r = 0;
	center.i = 0;
	origin.r = 0.285;
	origin.i = 0.01;
	conn = mlx_init();
	window = mlx_new_window(conn, 1500, 1000, "mlx 42");
	img.img = mlx_new_image(conn, 1500, 1000);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	grid = ft_get_grid(center, 500, 1500, 1000);
	grid = ft_mandelbrot_grid(grid);
	// grid = ft_julia_grid(grid, origin);
	ft_grid_to_img(grid, &img);
	mlx_put_image_to_window(conn, window, img.img, 0, 0);
	ft_clear_grid(grid);
	mlx_key_hook(window, ft_key_hook, conn);
	mlx_loop(conn);	
}
