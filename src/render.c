/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grhaddad <grhaddad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:36:53 by grhaddad          #+#    #+#             */
/*   Updated: 2025/11/04 14:36:54 by grhaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	fractal_render(t_fractal *fractal)
{
	int			y;
	int			adaptive_iterations;
	int			original_iterations;

	adaptive_iterations = get_adaptive_iterations(fractal);
	original_iterations = fractal->iterations_definition;
	fractal->iterations_definition = adaptive_iterations;
	y = -1;
	while (++y < HEIGHT)
		render_pixel_line(fractal, y);
	fractal->iterations_definition = original_iterations;
	mlx_put_image_to_window(fractal->mlx_connection,
		fractal->mlx_window, fractal->img.img_ptr, 0, 0);
}
