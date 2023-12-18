/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:16:13 by jeada-si          #+#    #+#             */
/*   Updated: 2023/12/18 14:49:06 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "mlx.h"
#include "fractal.h"

int main(void)
{
	void	*conn;
	void	*window;
	t_pxl	*grid;
	t_pxl	center;

	center.r = 1.6;
	center.i = 1.6;
	conn = mlx_init();
	window = mlx_new_window(conn, 500, 500, "mlx 42");
	grid = ft_get_grid(center, 200, 1000, 1000);
	grid = ft_julia_grid(grid, center);
	ft_display_grid(grid, conn, window);
	ft_clear_grid(grid);
	sleep(999999999);
	// mlx_destroy_window(conn, window);
}
