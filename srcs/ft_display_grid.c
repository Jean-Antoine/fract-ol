/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_grid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:22:07 by jeada-si          #+#    #+#             */
/*   Updated: 2023/12/19 15:49:04 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	create_trgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	ft_display_grid(t_pxl *grid, void *mlx, void *win)
{
	t_pxl	*node;

	node = grid;
	while (node)
	{
		mlx_pixel_put(mlx, win, node->x, node->y,
			create_trgb(0, 0, node->color * 255 /MAX_ITER));
		node = node->next;
	}
}
