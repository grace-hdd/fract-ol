/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_sets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grhaddad <grhaddad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:37:11 by grhaddad          #+#    #+#             */
/*   Updated: 2025/11/07 10:33:38 by grhaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	mandelbrot_set(t_complex *z, t_complex *c, t_fractal *fractal)
{
	int			i;
	t_complex	z_iter;
	t_complex	z_squared;
	double		magnitude_squared;

	i = 0;
	c->real = z->real;
	c->imag = z->imag;
	z_iter.real = 0.0;
	z_iter.imag = 0.0;
	while (i < fractal->iterations_definition)
	{
		magnitude_squared = z_iter.real * z_iter.real
			+ z_iter.imag * z_iter.imag;
		if (magnitude_squared > 4.0)
			return (i);
		z_squared.real = z_iter.real * z_iter.real - z_iter.imag * z_iter.imag;
		z_squared.imag = 2.0 * z_iter.real * z_iter.imag;
		z_iter.real = z_squared.real + c->real;
		z_iter.imag = z_squared.imag + c->imag;
		++i;
	}
	return (i);
}

int	julia_set(t_complex *z, t_complex *c, t_fractal *fractal)
{
	t_complex	julia_constant;
	t_complex	pixel_point;

	(void)c;
	julia_constant.real = fractal->julia_x;
	julia_constant.imag = fractal->julia_y;
	pixel_point.real = z->real;
	pixel_point.imag = z->imag;
	return (julia_iteration(pixel_point, julia_constant,
			fractal->iterations_definition));
}

int	burning_ship_set(t_complex *z, t_complex *c, t_fractal *fractal)
{
	int			i;
	t_complex	temp;

	i = 0;
	c->real = z->real;
	c->imag = z->imag;
	z->real = 0.0;
	z->imag = 0.0;
	while (i < fractal->iterations_definition)
	{
		if ((z->real * z->real) + (z->imag * z->imag) > fractal->escape_value)
			return (i);
		temp.real = fabs(z->real);
		temp.imag = -fabs(z->imag);
		*z = complex_add(complex_multiply(temp, temp), *c);
		++i;
	}
	return (i);
}
