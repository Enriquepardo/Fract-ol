/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enpardo- <enpardo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 13:20:48 by beade-va          #+#    #+#             */
/*   Updated: 2025/08/05 01:46:19 by enpardo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 800
# define HEIGHT 800
# define RE_MIN -2.0
# define RE_MAX 1.0
# define IM_MIN -1.5
# define IM_MAX 1.5
# define KEY_ESC 65307
# define ZOOM_IN 4
# define ZOOM_OUT 5

# include "minilibx-linux/mlx.h"
# include <stdbool.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_fractal
{
	void	*mlx;
	void	*win;
	void	*image;
	char	*addr;

	int		type;
	double	zoom;
	double	offset_x;
	double	offset_y;

	int		bits_per_pixel;
	int		line_length;
	int		endian;

	double	mouse_x;
	double	mouse_y;

	int		iterations;
}			t_fractal;

typedef struct s_viewport
{
	double	min;
	double	max;
	double	zoom;
	double	offset;
}			t_viewport;

typedef struct s_complex
{
	double	real;
	double	imag;
}			t_complex;

int			mandelbrot(double real, double imag, int max_iter);
int			julia(t_complex point, t_complex constant, int max_iter);
double		map_fractal(int pixel, int max_pixel, t_viewport vp);
void		draw_my_pixel(t_fractal *fractal, int x, int y, int color);
void		draw(t_fractal *data);
void		process_pixel(t_fractal *fractal, int x, int y);
int			get_color(int iter);
void		init_fractal(t_fractal *fractal);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		ft_putstr(char *s);
int			mouse_zoom(int button, int x, int y, t_fractal *fractal);
int			close_window(t_fractal *fractal);
int			key_hook(int keycode, void *fractal);
void		init_julia(t_fractal *fractal, double mouse_x, double mouse_y);
void		init_mandelbrot(t_fractal *fractal);
bool		is_valid_float(const char *str);
double		ft_atof(const char *s);
int			parse_args(int argc, char **argv, t_fractal *fractal);
void		print_error(void);
t_viewport	create_viewport(double min, double max, double zoom, double offset);
int			get_iteration(t_fractal *f, double real, double imag);

#endif
