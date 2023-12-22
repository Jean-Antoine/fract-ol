/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 10:36:26 by jeada-si          #+#    #+#             */
/*   Updated: 2023/12/22 15:50:34 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#include <X11/keysym.h>

int	ft_key_hook(int keycode, void *param)
{
	t_window	*window;

	window = (t_window *)param;
	if (keycode == XK_Escape)
		ft_close_window(window);
	else if (keycode == XK_Home)
		ft_home_view(window);
	else if (keycode == XK_Left)
		window->center.r = ft_pxl_to_cmplx(
				window->width / 2 - 0.1 * window->width, 0, window).r;
	else if (keycode == XK_Up)
		window->center.i = ft_pxl_to_cmplx(
				0, window->height / 2 - 0.1 * window->height, window).i;
	else if (keycode == XK_Right)
		window->center.r = ft_pxl_to_cmplx(
				window->width / 2 + 0.1 * window->width, 0, window).r;
	else if (keycode == XK_Down)
		window->center.i = ft_pxl_to_cmplx(
				0, window->height / 2 + 0.1 * window->height, window).i;
	ft_update_window(param);
	return (0);
}
