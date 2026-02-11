/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grhaddad <grhaddad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:37:19 by grhaddad          #+#    #+#             */
/*   Updated: 2025/11/07 14:28:23 by grhaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	exit(EXIT_SUCCESS);
}

int	key_handler(int keysym, t_fractal *fractal)
{
	if (keysym == ESCAPE)
		close_handler(fractal);
	else if (keysym == LEFT)
		fractal->shift_x -= (0.3 * fractal->zoom);
	else if (keysym == RIGHT)
		fractal->shift_x += (0.3 * fractal->zoom);
	else if (keysym == UP)
		fractal->shift_y += (0.3 * fractal->zoom);
	else if (keysym == DOWN)
		fractal->shift_y -= (0.3 * fractal->zoom);
	else if (keysym == KEY_PLUS)
		fractal->iterations_definition += 10;
	else if (keysym == KEY_MINUS && fractal->iterations_definition > 10)
		fractal->iterations_definition -= 10;
	else if (keysym == Q)
		fractal->render_quality = (fractal->render_quality % 4) + 1;
	else if (keysym == S)
		fractal->smooth_zoom = !fractal->smooth_zoom;
	fractal_render(fractal);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	double	mouse_x;
	double	mouse_y;
	double	zoom_factor;

	mouse_x = (map(x, -2, +2, WIDTH) * fractal->zoom) + fractal->shift_x;
	mouse_y = (map(y, +2, -2, HEIGHT) * fractal->zoom) + fractal->shift_y;
	if (button == BUTTON5)
		zoom_factor = 0.8;
	else if (button == BUTTON4)
		zoom_factor = 1.3;
	else
		return (0);
	fractal->shift_x = mouse_x - (mouse_x - fractal->shift_x) * zoom_factor;
	fractal->shift_y = mouse_y - (mouse_y - fractal->shift_y) * zoom_factor;
	fractal->zoom *= zoom_factor;
	fractal_render(fractal);
	return (0);
}
