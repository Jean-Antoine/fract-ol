/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expose_hook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 13:50:01 by jeada-si          #+#    #+#             */
/*   Updated: 2024/01/09 07:01:20 by jeada-si         ###   ########.fr       */
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
	return (0);
}
