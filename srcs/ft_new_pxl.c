/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_pxl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 09:46:53 by jeada-si          #+#    #+#             */
/*   Updated: 2023/12/21 16:10:35 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

t_pxl	*ft_new_pxl(int x, int y, t_window *window)
{
	t_pxl	*node;

	node = (t_pxl *) malloc(sizeof(t_pxl));
	node->x = x;
	node->y = y;
	node->z = ft_pxl_to_cmplx((float)x, (float)y, window);
	node->color = 0;
	node->next = 0;
	return (node);
}
