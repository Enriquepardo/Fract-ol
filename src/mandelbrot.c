/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enpardo- <enpardo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 19:24:16 by beade-va          #+#    #+#             */
/*   Updated: 2025/09/18 12:08:51 by enpardo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	mandelbrot(double real, double imag, int max_iter)
{
	double	z_real;
	double	z_imag;
	int		i;
	double	temp;

	z_real = 0;
	z_imag = 0;
	i = 0;
	while (i < max_iter && (z_real * z_real + z_imag * z_imag) <= 4)
	{
		temp = z_real * z_real - z_imag * z_imag + real;
		z_imag = 2 * z_real * z_imag + imag;
		z_real = temp;
		i++;
	}
	return (i);
}
