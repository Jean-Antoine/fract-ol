/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_grid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:19:57 by jeada-si          #+#    #+#             */
/*   Updated: 2023/12/21 15:08:44 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	ft_clear_grid(t_pxl *grid)
{
	t_pxl	*node;

	if (!grid)
		return ;
	while (grid)
	{
		node = grid;
		grid = grid->next;
		free(node);
	}
}
