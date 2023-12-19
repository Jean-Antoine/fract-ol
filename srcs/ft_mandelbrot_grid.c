/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot_grid.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:30:33 by jeada-si          #+#    #+#             */
/*   Updated: 2023/12/19 15:31:30 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static int	ft_iterate(float r, float i, float cr, float ci)
{
	int		iter;
	float	tmp;

	iter = 0;
	while (iter < MAX_ITER && (r * r + i * i) < 4)
	{
		tmp = r;
		r = r * r - i * i + cr;
		i = 2 * tmp * i + ci;
		iter++;
	}
	return (iter);
}

t_pxl	*ft_mandelbrot_grid(t_pxl *grid)
{
	t_pxl	*node;

	node = grid;
	while (node)
	{
		node->color = ft_iterate(node->r, node->i, node->r, node->i);
		node = node->next;
	}	
	return (grid);
}
