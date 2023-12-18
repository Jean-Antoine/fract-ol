/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_grid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:19:57 by jeada-si          #+#    #+#             */
/*   Updated: 2023/12/18 11:22:13 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	ft_clear_grid(t_pxl *grid)
{
	t_pxl	*node;

	while (grid)
	{
		node = grid;
		grid = grid->next;
		free(node);
	}
}
