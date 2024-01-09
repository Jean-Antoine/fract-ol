/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 08:34:26 by jeada-si          #+#    #+#             */
/*   Updated: 2024/01/09 12:48:06 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static int	ft_print_usage(void)
{
	ft_printf("Usage:\n");
	ft_printf("	./fractol [index]\n\n");
	ft_printf("Available fractals:\n");
	ft_printf("	1. Julia : 		./fractol 1 [Optional1] [Optional2]\n");
	ft_printf("	2. Mandelbrot : 	./fractol 2\n");
	ft_printf("	3. Burning Ship : 	./fractol 3\n\n");
	ft_printf("For Julia you may specify origin as follow:\n");
	ft_printf("	./fractol 1 [Real part] [Imaginary part]\n");
	ft_printf("	Ex: ./fractol 1 0.285 0.01\n");
	ft_printf("	N.B.: Values must be between -2 and 2\n\n");
	ft_printf("Navigation:\n");
	ft_printf("	Mouse wheel		Zoom in/out following mouse position\n");
	ft_printf("	Arrows			Move position\n");
	ft_printf("	Home			Reset zoom and position\n");
	ft_printf("	Left button mouse	Change Julia origin\n");
	ft_printf("	Space			Shift colors\n");
	ft_printf("	ESC			Quit program\n");\
	return (0);
}

static int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

int	ft_parse_origin(char **av, t_window *window)
{
	window->origin.r = ft_atof(av[2]);
	window->origin.i = ft_atof(av[3]);
	if (window->origin.r < -2 || window->origin.r > 2)
		return (0);
	if (window->origin.i < -2 || window->origin.i > 2)
		return (0);
	return (1);
}

int	ft_read_param(int ac, char **av, t_window *window)
{
	if (ac == 1)
		return (ft_print_usage());
	if (ft_strcmp(av[1], "1") == 0)
		window->type = JULIA;
	else if (ft_strcmp(av[1], "2") == 0)
		window->type = MANDELBROT;
	else if (ft_strcmp(av[1], "3") == 0)
		window->type = BURNINGSHIP;
	else
		return (ft_print_usage());
	if (window->type == MANDELBROT && ac != 2)
		return (ft_print_usage());
	if (window->type == JULIA && !(ac == 2 || ac == 4))
		return (ft_print_usage());
	if (window->type == JULIA && ac == 4)
		return (ft_parse_origin(av, window));
	else
	{
		window->origin.r = 0.285;
		window->origin.i = 0.01;
	}
	return (1);
}
