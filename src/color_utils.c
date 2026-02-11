/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grhaddad <grhaddad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 11:15:00 by grhaddad          #+#    #+#             */
/*   Updated: 2025/11/07 12:28:19 by grhaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	init_mandelbrot_colors(int *colors)
{
	colors[0] = 0x4B0082;
	colors[1] = 0x663399;
	colors[2] = 0x8A2BE2;
	colors[3] = 0x9932CC;
	colors[4] = 0xBA55D3;
	colors[5] = 0xDA70D6;
	colors[6] = 0xDDA0DD;
	colors[7] = 0xE6E6FA;
}

static void	init_julia_colors(int *colors)
{
	colors[0] = 0x87A96B;
	colors[1] = 0x9CAF88;
	colors[2] = 0x798B66;
	colors[3] = 0xA4B494;
	colors[4] = 0x8FBC8F;
	colors[5] = 0x90EE90;
	colors[6] = 0x98FB98;
	colors[7] = 0xF0FFF0;
}

static void	init_burning_colors(int *colors)
{
	colors[0] = 0x2A1000;
	colors[1] = 0x4A2000;
	colors[2] = 0x663300;
	colors[3] = 0x994400;
	colors[4] = 0xCC6600;
	colors[5] = 0xFF8800;
	colors[6] = 0xFFAA00;
	colors[7] = 0xFFDD44;
}

int	get_fractal_color(int i, t_fractal *fractal)
{
	int	colors[8];

	if (i == fractal->iterations_definition)
		return (BLACK);
	if (fractal->smooth_zoom)
		return (get_smooth_color(i, fractal));
	if (!ft_strncmp(fractal->name, "mandelbrot", 10))
		init_mandelbrot_colors(colors);
	else if (!ft_strncmp(fractal->name, "julia", 5))
		init_julia_colors(colors);
	else
		init_burning_colors(colors);
	return (colors[i % 8]);
}
