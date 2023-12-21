/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_window.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:42:05 by jeada-si          #+#    #+#             */
/*   Updated: 2023/12/21 15:59:16 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static t_img *ft_create_img(t_window *window)
{
	t_img	*img;
	
	if (!window)
		return (NULL);
	img = (t_img *)malloc(sizeof(t_img));
	if (!img)
		return(NULL);
	img->img = mlx_new_image(window->conn, window->width, window->height);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	return (img);
}

static void ft_clear_img(t_window *window, t_img *img)
{
	if (!img)
		return ;
	mlx_destroy_image(window->conn, img->img);
	free(img);
}

static void ft_update_img(t_window *window)
{
	if (!window)
		return ;
	window->next = ft_create_img(window);
	ft_grid_to_img(window->grid, window->next);
	mlx_put_image_to_window(window->conn, window->window, 
		window->next->img, 0, 0);
	ft_clear_img(window, window->current);
		window->current = window->next;
}

void	ft_update_window(t_window *window)
{
	if (!window)
		return ;
	ft_update_grid(window);
	if (window->type == 0)
		window->grid = ft_mandelbrot_grid(window->grid);
	else if (window->type == 1)
		window->grid = ft_julia_grid(window->grid, window->origin);
	ft_update_img(window);
}

