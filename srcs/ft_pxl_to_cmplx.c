/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pxl_to_cmplx.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:21:56 by jeada-si          #+#    #+#             */
/*   Updated: 2023/12/21 21:27:15 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

t_cmplx	ft_pxl_to_cmplx(float x, float y, t_window *window)
{
	t_cmplx	cmplx;

	cmplx.r = (x - window->width / 2) / window->zoom + window->center.r;
	cmplx.i = (y - window->height / 2) / window->zoom + window->center.i;
	return (cmplx);
}