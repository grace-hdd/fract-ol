/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grhaddad <grhaddad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:37:01 by grhaddad          #+#    #+#             */
/*   Updated: 2025/11/07 12:28:19 by grhaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	print_usage(void)
{
	ft_putstr_fd("Error: Invalid parameters\n", 2);
	ft_putstr_fd("Usage:\n", 2);
	ft_putstr_fd("  ./fractol mandelbrot\n", 2);
	ft_putstr_fd("  ./fractol julia <real> <imaginary>\n", 2);
	ft_putstr_fd("  ./fractol burning_ship\n", 2);
	ft_putstr_fd("Examples:\n", 2);
	ft_putstr_fd("  ./fractol julia -0.7 0.27015\n", 2);
	ft_putstr_fd("  ./fractol julia 0.3 0.5\n", 2);
}

static void	handle_julia(int argc, char **argv, t_fractal *fractal)
{
	if (argc == 4 && !ft_strncmp(argv[1], "julia", 5))
	{
		if (!is_valid_float(argv[2]) || !is_valid_float(argv[3]))
		{
			ft_putstr_fd("Error: Julia parameters must be valid numbers\n", 2);
			ft_putstr_fd("Example: ./fractol julia -0.7 0.27015\n", 2);
			exit(EXIT_FAILURE);
		}
		fractal->name = argv[1];
		fractal->julia_x = atof(argv[2]);
		fractal->julia_y = atof(argv[3]);
		fractal_init(fractal);
		fractal_render(fractal);
		mlx_loop(fractal->mlx_connection);
	}
}

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
		|| (argc == 2 && !ft_strncmp(argv[1], "burning_ship", 12)))
	{
		fractal.name = argv[1];
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else if (argc == 4 && !ft_strncmp(argv[1], "julia", 5))
		handle_julia(argc, argv, &fractal);
	else
	{
		print_usage();
		exit(EXIT_FAILURE);
	}
}
