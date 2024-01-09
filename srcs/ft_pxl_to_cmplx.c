/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pxl_to_cmplx.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:21:56 by jeada-si          #+#    #+#             */
/*   Updated: 2024/01/09 11:19:57 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

t_cmplx	ft_pxl_to_cmplx(float x, float y, t_window *window)
{
	t_cmplx	cmplx;

	cmplx.r = (x - WINDOW_WIDTH / 2) / window->zoom + window->center.r;
	cmplx.i = (y - WINDOW_HEIGHT / 2) / window->zoom + window->center.i;
	return (cmplx);
}
