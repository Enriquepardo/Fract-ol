/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beade-va <beade-va@student.42.madrid>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 12:14:45 by beade-va          #+#    #+#             */
/*   Updated: 2025/07/30 23:02:26 by beade-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_window(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->image);
	mlx_destroy_window(fractal->mlx, fractal->win);
	exit(0);
	return (0);
}

int	key_hook(int keycode, void *fractal)
{
	t_fractal	*fractal_ptr;

	if (keycode == KEY_ESC)
	{
		fractal_ptr = (t_fractal *)fractal;
		close_window(fractal_ptr);
	}
	return (0);
}

int	mouse_zoom(int button, int x, int y, t_fractal *fractal)
{
	t_viewport	re_view;
	t_viewport	im_view;
	double		before_re;
	double		before_im;

	re_view = create_viewport(RE_MIN, RE_MAX, fractal->zoom, fractal->offset_x);
	im_view = create_viewport(IM_MIN, IM_MAX, fractal->zoom, fractal->offset_y);
	before_re = map_fractal(x, WIDTH, re_view);
	before_im = map_fractal(y, HEIGHT, im_view);
	if (button == ZOOM_IN)
		fractal->zoom *= 1.1;
	else if (button == ZOOM_OUT)
		fractal->zoom /= 1.1;
	re_view = create_viewport(RE_MIN, RE_MAX, fractal->zoom, fractal->offset_x);
	im_view = create_viewport(IM_MIN, IM_MAX, fractal->zoom, fractal->offset_y);
	fractal->offset_x += before_re - map_fractal(x, WIDTH, re_view);
	fractal->offset_y += before_im - map_fractal(y, HEIGHT, im_view);
	draw(fractal);
	return (0);
}
