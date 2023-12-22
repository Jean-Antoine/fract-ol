/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 17:07:10 by jeada-si          #+#    #+#             */
/*   Updated: 2023/12/22 17:10:46 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	ft_close_window(t_window *window)
{
	if (!window)
		return (0);
	ft_clear_grid(window->grid);
	ft_clear_img(window, window->current);
	mlx_destroy_window(window->conn, window->window);
	mlx_destroy_display(window->conn);
	free(window->conn);
	exit(0);
	return (0);
}
