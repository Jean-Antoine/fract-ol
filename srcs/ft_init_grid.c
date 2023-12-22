/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_grid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 09:25:02 by jeada-si          #+#    #+#             */
/*   Updated: 2023/12/22 16:48:11 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	ft_init_grid(t_window *window)
{
	int		i;
	int		j;
	t_pxl	*node;

	i = 0;
	window->grid = ft_new_pxl(0, 0);
	node = window->grid;
	while (i < window->width)
	{
		j = 0;
		while (j < window->height)
		{
			node->next = ft_new_pxl(i, j);
			node = node->next;
			j++;
		}
		i++;
	}
	node = window->grid;
	window->grid = window->grid->next;
	free(node);
}
