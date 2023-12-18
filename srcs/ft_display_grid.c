/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_grid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:22:07 by jeada-si          #+#    #+#             */
/*   Updated: 2023/12/18 14:26:17 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	ft_display_grid(t_pxl *grid, void *mlx, void *win)
{
	t_pxl	*node;

	node = grid;
	while (node)
	{
		mlx_pixel_put(mlx, win, node->x, node->y, node->color);
		node = node->next;
	}
}
