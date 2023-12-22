/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_pxl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 09:46:53 by jeada-si          #+#    #+#             */
/*   Updated: 2023/12/22 16:47:44 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

t_pxl	*ft_new_pxl(int x, int y)
{
	t_pxl	*node;
	t_cmplx	z;

	z.i = 0;
	z.r = 0;
	node = (t_pxl *) malloc(sizeof(t_pxl));
	node->x = x;
	node->y = y;
	node->z = z;
	node->color = 0;
	node->next = 0;
	return (node);
}
