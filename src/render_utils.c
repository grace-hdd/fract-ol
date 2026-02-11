/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grhaddad <grhaddad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:36:55 by grhaddad          #+#    #+#             */
/*   Updated: 2025/11/07 12:28:19 by grhaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

static int	calculate_fractal(t_complex *z, t_complex *c, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "mandelbrot", 10))
		return (mandelbrot_set(z, c, fractal));
	else if (!ft_strncmp(fractal->name, "julia", 5))
		return (julia_set(z, c, fractal));
	else if (!ft_strncmp(fractal->name, "burning_ship", 12))
		return (burning_ship_set(z, c, fractal));
	return (0);
}

void	render_pixel_line(t_fractal *fractal, int y)
{
	int			x;
	t_complex	z;
	t_complex	c;
	int			color;

	x = -1;
	while (++x < WIDTH)
	{
		z.real = (map(x, -2, +2, WIDTH) * fractal->zoom) + fractal->shift_x;
		z.imag = (map(y, +2, -2, HEIGHT) * fractal->zoom) + fractal->shift_y;
		color = get_fractal_color(calculate_fractal(&z, &c, fractal), fractal);
		my_pixel_put(x, y, &fractal->img, color);
	}
}
