/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_burningship_grid.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:23:59 by jeada-si          #+#    #+#             */
/*   Updated: 2024/01/09 12:54:26 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fractal.h"

static double	ft_abs(double n)
{
	if (n >= 0)
		return (n);
	else
		return (n * -1);
}

static int	ft_iterate(t_cmplx z)
{
	int		iter;
	float	tmp;
	float	r0;
	float	i0;

	r0 = z.r;
	i0 = z.i;
	iter = 0;
	while (iter < MAX_ITER && (z.r * z.r + z.i * z.i) < 4)
	{
		tmp = z.r;
		z.r = z.r * z.r - z.i * z.i + r0;
		z.i = 2 * ft_abs(tmp) * ft_abs(z.i) + i0;
		iter++;
	}
	return (iter);
}

t_pxl	*ft_burningship_grid(t_pxl *grid)
{
	t_pxl	*node;

	node = grid;
	while (node)
	{
		node->color = ft_iterate(node->z);
		node = node->next;
	}
	return (grid);
}