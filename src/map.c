/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enpardo- <enpardo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 13:13:45 by beade-va          #+#    #+#             */
/*   Updated: 2025/09/18 12:08:53 by enpardo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

double	map_fractal(int pixel, int max_pixel, t_viewport vp)
{
	double	range;

	range = (vp.max - vp.min) / vp.zoom;
	return (vp.min + vp.offset + ((double)pixel / max_pixel) * range);
}
