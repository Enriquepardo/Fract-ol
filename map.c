/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beade-va <beade-va@student.42.madrid>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 13:13:45 by beade-va          #+#    #+#             */
/*   Updated: 2025/07/28 11:38:01 by beade-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	map_fractal(int pixel, int max_pixel, t_viewport vp)
{
	double	range;

	range = (vp.max - vp.min) / vp.zoom;
	return (vp.min + vp.offset + ((double)pixel / max_pixel) * range);
}
