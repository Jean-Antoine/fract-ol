/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_grid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 09:25:02 by jeada-si          #+#    #+#             */
/*   Updated: 2023/12/22 16:45:47 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	ft_update_grid(t_window *window)
{
	int		i;
	int		j;
	t_pxl	*node;

	i = 0;
	node = window->grid;
	while (i < window->width)
	{
		j = 0;
		while (j < window->height)
		{
			node->z = ft_pxl_to_cmplx(i, j, window);
			node = node->next;
			j++;
		}
		i++;
	}
}
