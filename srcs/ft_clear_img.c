/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_img.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 17:10:30 by jeada-si          #+#    #+#             */
/*   Updated: 2023/12/22 17:10:38 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	ft_clear_img(t_window *window, t_img *img)
{
	if (!img)
		return ;
	mlx_destroy_image(window->conn, img->img);
	free(img);
}
