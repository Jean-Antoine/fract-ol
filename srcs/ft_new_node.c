/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 09:46:53 by jeada-si          #+#    #+#             */
/*   Updated: 2023/12/18 16:13:42 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

t_pxl	*ft_new_node(int x, int y, float r, float i)
{
	t_pxl	*node;

	node = (t_pxl *) malloc(sizeof(t_pxl));
	node->x = x;
	node->y = y;
	node->r = r;
	node->i = i;
	node->color = 0;
	node->next = 0;
	return (node);
}
