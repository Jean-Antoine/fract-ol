/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grid_to_img.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:22:07 by jeada-si          #+#    #+#             */
/*   Updated: 2023/12/22 16:51:41 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	ft_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	ft_grid_to_img(t_pxl *grid, t_img *img)
{
	t_pxl	*node;
	char	*offset;

	node = grid;
	while (node)
	{
		offset = img->addr + (node->y * img->line_length + node->x
				* (img->bits_per_pixel / 8));
		if (node->color)
			*(unsigned int *)offset = node->color * 10 + 0x000000FF;
		node = node->next;
	}
}
