/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grhaddad <grhaddad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:36:38 by grhaddad          #+#    #+#             */
/*   Updated: 2025/11/07 12:28:19 by grhaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

double	map(double unscaled_num, double new_min, double new_max, double old_max)
{
	return ((new_max - new_min) * unscaled_num / old_max + new_min);
}

int	get_adaptive_iterations(t_fractal *fractal)
{
	if (fractal->zoom > 8.0)
		return (fractal->iterations_definition * 0.6);
	else if (fractal->zoom > 4.0)
		return (fractal->iterations_definition * 0.8);
	else
		return (fractal->iterations_definition);
}
