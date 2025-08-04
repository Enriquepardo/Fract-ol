/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beade-va <beade-va@student.42.madrid>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 22:23:42 by beade-va          #+#    #+#             */
/*   Updated: 2025/07/28 12:13:06 by beade-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_my_pixel(t_fractal *fractal, int x, int y, int color)
{
	char	*dst;

	dst = fractal->addr + (y * fractal->line_length + x
			* (fractal->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	process_pixel(t_fractal *f, int x, int y)
{
	double	real;
	double	imag;
	int		iter;

	real = map_fractal(x, WIDTH, create_viewport(RE_MIN, RE_MAX, f->zoom,
				f->offset_x));
	imag = map_fractal(y, HEIGHT, create_viewport(IM_MIN, IM_MAX, f->zoom,
				f->offset_y));
	iter = get_iteration(f, real, imag);
	if (iter == f->iterations)
		draw_my_pixel(f, x, y, 0x000000);
	else
		draw_my_pixel(f, x, y, get_color(iter));
}

int	get_iteration(t_fractal *f, double real, double imag)
{
	t_complex	z;
	t_complex	c;

	if (f->type == 0)
		return (mandelbrot(real, imag, f->iterations));
	if (f->type == 1)
	{
		z.real = real;
		z.imag = imag;
		c.real = f->mouse_x;
		c.imag = f->mouse_y;
		return (julia(z, c, f->iterations));
	}
	return (0);
}

void	draw(t_fractal *fractal)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			process_pixel(fractal, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->image, 0, 0);
}

int	get_color(int iter)
{
	int	g;
	int	b;
	int	r;

	r = (iter * 9) % 256;
	g = (iter * 2) % 256;
	b = (iter * 5) % 256;
	return (r << 16 | g << 8 | b);
}
