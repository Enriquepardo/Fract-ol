/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enpardo- <enpardo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 00:18:16 by beade-va          #+#    #+#             */
/*   Updated: 2025/08/05 01:38:10 by enpardo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_fractal(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	if (!fractal->mlx)
		exit(1);
	fractal->win = mlx_new_window(fractal->mlx, WIDTH, HEIGHT,
			"Fract-ol42-> enpardo-");
	if (!fractal->win)
		exit(1);
	fractal->image = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	if (!fractal->image)
		exit(1);
	fractal->addr = mlx_get_data_addr(fractal->image, &fractal->bits_per_pixel,
			&fractal->line_length, &fractal->endian);
	fractal->iterations = 100;
}

void	init_mandelbrot(t_fractal *fractal)
{
	fractal->type = 0;
	fractal->zoom = 1.0;
	fractal->offset_x = 0.0;
	fractal->offset_y = 0.0;
}

void	init_julia(t_fractal *fractal, double mouse_x, double mouse_y)
{
	fractal->type = 1;
	fractal->zoom = 0.8;
	fractal->offset_x = 0.0;
	fractal->offset_y = 0.2;
	fractal->mouse_x = mouse_x;
	fractal->mouse_y = mouse_y;
}
