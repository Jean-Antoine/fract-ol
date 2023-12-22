/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:04:57 by jeada-si          #+#    #+#             */
/*   Updated: 2023/12/22 16:58:56 by jeada-si         ###   ########.fr       */
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
	else if (button == 4)
		zoom_factor = 1.25;
	else if (button == 5)
		zoom_factor = 1 / 1.25;	
	if (button == 4 || button == 5)
	{
		zoom_center = ft_pxl_to_cmplx((float)x, (float)y, window);
		window->center.r = zoom_center.r
			- (x - window->width / 2) / (window->zoom * zoom_factor);
		window->center.i = zoom_center.i
			- (y - window->height / 2) / (window->zoom * zoom_factor);
		window->zoom *= zoom_factor;
	}
	ft_update_window(param);
	return (0);
}
