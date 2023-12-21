/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia_grid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:14:34 by jeada-si          #+#    #+#             */
/*   Updated: 2023/12/21 15:54:23 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static int	ft_iterate(t_cmplx z, t_cmplx c)
{
	int		iter;
	float	tmp;

	iter = 0;
	while (iter < MAX_ITER && (z.r * z.r + z.i * z.i) < 4)
	{
		tmp = z.r;
		z.r = z.r * z.r - z.i * z.i + c.r;
		z.i = 2 * tmp * z.i + c.i;
		iter++;
	}
	return (iter);
}

t_pxl	*ft_julia_grid(t_pxl *grid, t_cmplx c)
{
	t_pxl	*node;

	node = grid;
	while (node)
	{
		node->color = ft_iterate(node->z, c);
		node = node->next;
	}	
	return (grid);
}
