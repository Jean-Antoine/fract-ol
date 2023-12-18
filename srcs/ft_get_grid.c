/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_grid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 09:25:02 by jeada-si          #+#    #+#             */
/*   Updated: 2023/12/18 14:25:38 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

t_pxl	*ft_get_grid(t_cmplx center, int zoom, int width, int height)
{
	int		i;
	int		j;
	t_pxl	*grid;
	t_pxl	*node;

	i = 0;
	grid = ft_new_node(0, 0, 0, 0);
	node = grid;
	while (i < width)
	{
		j = 0;
		while (j < height)
		{
			node->next = ft_new_node(i, j, center.r + (i - width / 2) / zoom,
					center.i + (j - height / 2) / zoom);
			node = node->next;
			j++;
		}
		i++;
	}
	node = grid;
	grid = grid->next;
	free(node);
	return (grid);
}
