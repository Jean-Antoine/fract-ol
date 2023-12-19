/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:16:13 by jeada-si          #+#    #+#             */
/*   Updated: 2023/12/19 15:51:25 by jeada-si         ###   ########.fr       */
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

	center.r = 0;
	center.i = 0;
	origin.r = 0.285;
	origin.i = 0.01;
	conn = mlx_init();
	window = mlx_new_window(conn, 1000, 1000, "mlx 42");
	grid = ft_get_grid(center, 400, 1000, 1000);
	// grid = ft_mandelbrot_grid(grid);
	grid = ft_julia_grid(grid, origin);
	ft_display_grid(grid, conn, window);
	ft_clear_grid(grid);
	sleep(3);	
	mlx_destroy_window(conn, window);
}
