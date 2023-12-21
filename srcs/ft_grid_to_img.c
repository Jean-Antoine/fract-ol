/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grid_to_img.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:22:07 by jeada-si          #+#    #+#             */
/*   Updated: 2023/12/21 16:28:20 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

// static int	create_rgb(int r, int g, int b)
// {
// 	return (r << 16 | g << 8 | b);
// }

void	ft_grid_to_img(t_pxl *grid, t_img *img)
{
	t_pxl	*node;
	char	*offset;
	
	node = grid;
	while (node)
	{
		offset = img->addr + (node->y * img->line_length + node->x
				* (img->bits_per_pixel / 8));
		// if (node->color == MAX_ITER)
		// 	*(unsigned int *)offset = 0;
		// else
			*(unsigned int *)offset = node->color * 10 << 16;
		node = node->next; 
	}
}
