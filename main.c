/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:16:13 by jeada-si          #+#    #+#             */
/*   Updated: 2023/12/21 22:31:36 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	main(void)
{
	t_window	window;

	window.zoom = 100;
	window.width = 1000;
	window.height = 500;
	window.type = 1;
	window.center.r = 0;
	window.center.i = 0;
	window.origin.r = 0.285;
	window.origin.i = 0.01;
	window.grid = NULL;
	window.current = NULL;
	window.next = NULL;
	window.conn = mlx_init();
	window.window = mlx_new_window(window.conn, 
		window.width, window.height, "Fract-ol");		
	ft_update_window(&window);	
	mlx_key_hook(window.window, ft_key_hook, &window);
	mlx_expose_hook(window.window, ft_expose_hook, &window);
	mlx_mouse_hook(window.window, ft_mouse_hook, &window);
	mlx_loop(window.conn);
}
