/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia_grid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:14:34 by jeada-si          #+#    #+#             */
/*   Updated: 2023/12/19 15:19:03 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static int	ft_iterate(float r, float i, t_cmplx c)
{
	int		iter;
	float	tmp;

	iter = 0;
	while (iter < MAX_ITER && (r * r + i * i) < 4)
	{
		tmp = r;
		r = r * r - i * i + c.r;
		i = 2 * tmp * i + c.i;
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
		node->color = ft_iterate(node->r, node->i, c);
		node = node->next;
	}	
	return (grid);
}
