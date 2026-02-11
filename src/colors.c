/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grhaddad <grhaddad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:37:23 by grhaddad          #+#    #+#             */
/*   Updated: 2025/11/07 10:57:04 by grhaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	mandelbrot_color(double ratio)
{
	int		red;
	int		green;
	int		blue;

	red = (int)(255 * sin(ratio * 3.14159 + 1.0) * 0.8);
	green = (int)(255 * sin(ratio * 3.14159 + 2.0) * 0.3);
	blue = (int)(255 * sin(ratio * 3.14159) * sin(ratio * 3.14159));
	return ((red << 16) | (green << 8) | blue);
}

static int	julia_color(double ratio)
{
	int		red;
	int		green;
	int		blue;

	red = (int)(255 * sin(ratio * 3.14159 + 2.5) * 0.6);
	green = (int)(255 * sin(ratio * 3.14159) * 0.9);
	blue = (int)(255 * sin(ratio * 3.14159 + 1.5) * 0.5);
	return ((red << 16) | (green << 8) | blue);
}

static int	burning_ship_color(double ratio)
{
	int		red;
	int		green;
	int		blue;

	red = (int)(120 + 80 * sin(ratio * 3.14159));
	green = (int)(60 + 60 * sin(ratio * 3.14159 + 1.5));
	blue = (int)(30 + 40 * sin(ratio * 3.14159 + 3.0));
	return ((red << 16) | (green << 8) | blue);
}

int	get_smooth_color(int i, t_fractal *fractal)
{
	double	ratio;

	ratio = (double)i / fractal->iterations_definition;
	if (!ft_strncmp(fractal->name, "mandelbrot", 10))
		return (mandelbrot_color(ratio));
	else if (!ft_strncmp(fractal->name, "julia", 5))
		return (julia_color(ratio));
	else
		return (burning_ship_color(ratio));
}
