/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beade-va <beade-va@student.42.madrid>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 13:07:25 by beade-va          #+#    #+#             */
/*   Updated: 2025/07/28 11:49:57 by beade-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia(t_complex point, t_complex constant, int max_iter)
{
	int		i;
	double	temp;

	i = 0;
	while (i < max_iter && (point.real * point.real + point.imag
			* point.imag) <= 4)
	{
		temp = point.real * point.real - point.imag * point.imag
			+ constant.real;
		point.imag = 2 * point.real * point.imag + constant.imag;
		point.real = temp;
		i++;
	}
	return (i);
}
