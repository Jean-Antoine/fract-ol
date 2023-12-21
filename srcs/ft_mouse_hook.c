/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:04:57 by jeada-si          #+#    #+#             */
/*   Updated: 2023/12/21 22:12:46 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int ft_mouse_hook(int button, int x, int y, void *param)
{
	t_window	*window;
	t_cmplx		zoom_center;
	float		zoom_factor;

	window = (t_window *)param;
	if (button == 4)
		zoom_factor = 1.25;
	else if (button == 5)
		zoom_factor = 1 / 1.25;
	zoom_center = ft_pxl_to_cmplx((float)x, (float)y, window);
    window->center.r = zoom_center.r - (x - window->width / 2) / (window->zoom * zoom_factor);
    window->center.i = zoom_center.i - (y - window->height / 2) / (window->zoom * zoom_factor);
	window->zoom *= zoom_factor;
	ft_update_window(param);
	return (0);
}