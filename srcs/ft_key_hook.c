/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 10:36:26 by jeada-si          #+#    #+#             */
/*   Updated: 2023/12/21 22:28:49 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#include <X11/keysym.h>

int	ft_key_hook(int keycode, void *param)
{
	// t_window	*window;
	(void)param;
	// window = (t_window *)param;
	if (keycode == XK_Escape)
		exit(0);
	return (0);
}