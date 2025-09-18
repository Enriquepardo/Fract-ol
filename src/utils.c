/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enpardo- <enpardo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 19:26:36 by beade-va          #+#    #+#             */
/*   Updated: 2025/09/18 12:08:55 by enpardo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n && s1[i] && s2[i])
	{
		if (s1[i] == s2[i])
		{
			i++;
		}
		else
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
	}
	if (i < n)
	{
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	return (0);
}

void	ft_putstr(char *s)
{
	while (*s != '\0')
	{
		write(1, s, 1);
		s++;
	}
}

bool	is_valid_float(const char *str)
{
	int	i = 0;
	int	dot_count = 0;

	if (!str || !str[0])
		return (false);

	if (str[i] == '-' || str[i] == '+')
		i++;

	while (str[i])
	{
		if (str[i] == '.')
		{
			dot_count++;
			if (dot_count > 1)
				return (false);
		}
		else if (str[i] < '0' || str[i] > '9')
			return (false);
		i++;
	}
	return (true);
}

double	ft_atof(const char *str)
{
	double	res;
	double	frac;
	int		sign;
	int		i;

	res = 0.0;
	frac = 0.1;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
		res = res * 10 + (str[i++] - '0');
	if (str[i] == '.')
	{
		i++;
		while (str[i] >= '0' && str[i] <= '9')
		{
			res += (str[i++] - '0') * frac;
			frac *= 0.1;
		}
	}
	return (res * sign);
}

t_viewport	create_viewport(double min, double max, double zoom, double offset)
{
	t_viewport	vp;

	vp.min = min;
	vp.max = max;
	vp.zoom = zoom;
	vp.offset = offset;
	return (vp);
}
