/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:04:57 by jeada-si          #+#    #+#             */
/*   Updated: 2024/01/09 11:19:57 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	ft_mouse_hook(int button, int x, int y, void *param)
{
	t_window	*window;
	t_cmplx		zoom_center;
	float		zoom_factor;

	window = (t_window *)param;
	if (button == 2 || (button == 1 && window->type != JULIA))
		return (0);
	if (button == 1)
		window->origin = ft_pxl_to_cmplx((float)x, (float)y, window);
	if (button == 3)
		window->center = ft_pxl_to_cmplx((float)x, (float)y, window);
	else if (button == 5 || button == 4)
	{
		zoom_factor = (button == 5) * 1 / 1.25 + (button == 4) * 1.25;
		zoom_center = ft_pxl_to_cmplx((float)x, (float)y, window);
		window->center.r = zoom_center.r
			- (x - WINDOW_WIDTH / 2) / (window->zoom * zoom_factor);
		window->center.i = zoom_center.i
			- (y - WINDOW_HEIGHT / 2) / (window->zoom * zoom_factor);
		window->zoom *= zoom_factor;
	}
	ft_update_window(param);
	return (0);
}
