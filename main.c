/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:16:13 by jeada-si          #+#    #+#             */
/*   Updated: 2023/12/22 17:24:39 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	main(void)
{
	t_window	window;

	window.width = 500;
	window.height = 500;
	window.type = MANDELBROT;
	window.origin.r = 0.285;
	window.origin.i = 0.01;
	window.current = NULL;
	window.next = NULL;
	ft_init_grid(&window);
	ft_home_view(&window);	
	window.conn = mlx_init();
	window.window = mlx_new_window(window.conn,
			window.width, window.height, "Fract-ol");
	ft_update_window(&window);
	mlx_key_hook(window.window, ft_key_hook, &window);
	mlx_mouse_hook(window.window, ft_mouse_hook, &window);
	mlx_hook(window.window, 17, 0, ft_close_window, &window);
	mlx_loop(window.conn);
}
