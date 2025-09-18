/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enpardo- <enpardo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 13:27:22 by beade-va          #+#    #+#             */
/*   Updated: 2025/09/18 12:08:49 by enpardo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	print_error(void)
{
	ft_putstr("Error: ./fractol mandelbrot OR ./fractol julia [real] [imag]\n");
}

int	parse_args(int argc, char **argv, t_fractal *fractal)
{
	double	real;
	double	imag;

	if (argc < 2)
		return (print_error(), 1);
	if (ft_strncmp(argv[1], "mandelbrot", 10) == 0)
	{
		if (argc == 2)
			init_mandelbrot(fractal);
		else
			return (ft_putstr("Fractal invalid.\n"), 1);
	}
	else if (ft_strncmp(argv[1], "julia", 5) == 0)
	{
		if (argc != 4)
			return (print_error(), 1);
		if(!is_valid_float(argv[2]) || !is_valid_float(argv[3]))
			return (ft_putstr("Invalid float arguments for Julia.\n"), 1);
		real = ft_atof(argv[2]);
		imag = ft_atof(argv[3]);
		init_julia(fractal, real, imag);
	}
	else
		return (ft_putstr("Fractal invalid.\n"), 1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if (parse_args(argc, argv, &fractal))
		return (1);
	init_fractal(&fractal);
	mlx_hook(fractal.win, 17, 0, close_window, &fractal);
	mlx_mouse_hook(fractal.win, mouse_zoom, &fractal);
	mlx_key_hook(fractal.win, key_hook, &fractal);
	draw(&fractal);
	mlx_loop(fractal.mlx);
	return (0);
}
