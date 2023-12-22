/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expose_hook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 13:50:01 by jeada-si          #+#    #+#             */
/*   Updated: 2023/12/22 15:54:13 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	ft_expose_hook(void *param)
{
	t_window	*window;
	int			x;
	int			y;

	window = (t_window *)param;
	mlx_get_screen_size(window->conn, &x, &y);
	// __builtin_printf("expose hook: %d %d\n", x, y);
	return (0);
}
