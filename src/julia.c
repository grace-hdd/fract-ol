/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grhaddad <grhaddad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:37:03 by grhaddad          #+#    #+#             */
/*   Updated: 2025/11/04 14:37:03 by grhaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	julia_iteration(t_complex z, t_complex c, int max_iterations)
{
	double	z_real_temp;
	double	magnitude_squared;
	int		iteration;

	iteration = 0;
	while (iteration < max_iterations)
	{
		magnitude_squared = z.real * z.real + z.imag * z.imag;
		if (magnitude_squared > 4.0)
			break ;
		z_real_temp = z.real * z.real - z.imag * z.imag + c.real;
		z.imag = 2.0 * z.real * z.imag + c.imag;
		z.real = z_real_temp;
		iteration++;
	}
	return (iteration);
}
