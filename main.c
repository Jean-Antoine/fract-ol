/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:16:13 by jeada-si          #+#    #+#             */
/*   Updated: 2023/12/18 16:40:31 by jeada-si         ###   ########.fr       */
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
	origin.r = 0.6;
	origin.i = 0.2;
	conn = mlx_init();
	window = mlx_new_window(conn, 500, 500, "mlx 42");
	grid = ft_get_grid(center, 150, 500, 500);
	grid = ft_julia_grid(grid, origin);
	ft_display_grid(grid, conn, window);
	ft_clear_grid(grid);
	sleep(2);
	mlx_destroy_window(conn, window);
}
