/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grhaddad <grhaddad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:37:05 by grhaddad          #+#    #+#             */
/*   Updated: 2025/11/07 10:57:09 by grhaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	data_init(t_fractal *fractal)
{
	fractal->escape_value = 4;
	fractal->iterations_definition = 50;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
	fractal->render_quality = 1;
	fractal->smooth_zoom = 0;
	if (ft_strncmp(fractal->name, "julia", 5) != 0)
	{
		fractal->julia_x = -0.4;
		fractal->julia_y = 0.6;
	}
}

static void	events_init(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_window,
		KEY_PRESS,
		KEY_PRESS_MASK,
		key_handler,
		fractal);
	mlx_hook(fractal->mlx_window,
		BUTTON_PRESS,
		BUTTON_PRESS_MASK,
		mouse_handler,
		fractal);
	mlx_hook(fractal->mlx_window,
		DESTROY_NOTIFY,
		STRUCTURE_NOTIFY_MASK,
		close_handler,
		fractal);
}

void	fractal_init(t_fractal *fractal)
{
	init_mlx_connection(fractal);
	init_mlx_window(fractal);
	init_mlx_image(fractal);
	events_init(fractal);
	data_init(fractal);
}

void	malloc_error(void)
{
	perror("Problems with malloc");
	exit(EXIT_FAILURE);
}
