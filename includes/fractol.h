/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grhaddad <grhaddad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:36:32 by grhaddad          #+#    #+#             */
/*   Updated: 2025/11/07 16:14:34 by grhaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <../mlx/mlx.h>

# ifndef WIDTH
#  define WIDTH			800
# endif
# ifndef HEIGHT
#  define HEIGHT			600
# endif

/* Basic Colors */
# define BLACK			0x000000
# define WHITE			0xFFFFFF
# define RED			0xFF0000
# define GREEN			0x00FF00
# define BLUE			0x0000FF
# define MAGENTA		0xFF00FF
# define YELLOW			0xFFFF00
# define CYAN			0x00FFFF

/* Fractal Color Palette */
# define MAGENTA_BURST		0xFF00FF
# define LIME_SHOCK		0xCCFF00
# define NEON_ORANGE		0xFF6600
# define PSYCHEDELIC_PURPLE	0x660066
# define AQUA_DREAM		0x33CCCC
# define HOT_PINK		0xFF1493
# define ELECTRIC_BLUE		0x0066FF
# define LAVA_RED		0xFF3300

/* Navigation Keys */
# define KEY_ESC		65307		/* Escape key */
# define KEY_LEFT		65361		/* Left arrow */
# define KEY_RIGHT		65363		/* Right arrow */
# define KEY_UP			65362		/* Up arrow */
# define KEY_DOWN		65364		/* Down arrow */

/* Backward Compatibility */
# define ESCAPE			KEY_ESC
# define LEFT			KEY_LEFT
# define RIGHT			KEY_RIGHT
# define UP			KEY_UP
# define DOWN			KEY_DOWN

/* Control Keys */
# define KEY_PLUS		65451  	/* + key */
# define KEY_MINUS		65453		/* - key */
# define KEY_SPACE		32		/* Space bar */

/* Letter Keys */
# define KEY_Q			113		/* q key */
# define KEY_S			115		/* s key */
# define KEY_C			99		/* c key */

/* Backward Compatibility */
# define Q			KEY_Q
# define S			KEY_S

/* MLX Constants */
# define KEY_PRESS		2
# define BUTTON_PRESS		4
# define DESTROY_NOTIFY		17

# define KEY_PRESS_MASK		1
# define BUTTON_PRESS_MASK	4
# define STRUCTURE_NOTIFY_MASK	131072

# define BUTTON4		4
# define BUTTON5		5

/* Fractal Type Enumeration */
typedef enum e_fractal_type
{
	MANDELBROT,
	JULIA,
	BURNING_SHIP
}	t_fractal_type;

/* Complex Number Structure */
typedef struct s_complex
{
	double	real;
	double	imag;
}	t_complex;

/* Image Structure for MLX */
typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}	t_img;

/* Main Fractal Structure */
typedef struct s_fractal
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;
	double	escape_value;
	int		iterations_definition;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
	int		render_quality;
	int		smooth_zoom;
}	t_fractal;

int			ft_strncmp(char *s1, char *s2, int n);
void		ft_putstr_fd(char *s, int fd);
int			is_valid_float(char *str);

double		map(double unscaled_num, double new_min,
				double new_max, double old_max);

t_complex	complex_new(double real, double imag);
t_complex	complex_add(t_complex a, t_complex b);
t_complex	complex_multiply(t_complex a, t_complex b);

void		fractal_init(t_fractal *fractal);
void		init_mlx_connection(t_fractal *fractal);
void		init_mlx_window(t_fractal *fractal);
void		init_mlx_image(t_fractal *fractal);
void		malloc_error(void);

void		fractal_render(t_fractal *fractal);
int			get_adaptive_iterations(t_fractal *fractal);
void		render_pixel_line(t_fractal *fractal, int y);

int			mandelbrot_set(t_complex *z, t_complex *c, t_fractal *fractal);
int			julia_set(t_complex *z, t_complex *c, t_fractal *fractal);
int			burning_ship_set(t_complex *z, t_complex *c, t_fractal *fractal);

int			julia_iteration(t_complex z, t_complex c, int max_iterations);

int			get_smooth_color(int i, t_fractal *fractal);
int			get_fractal_color(int i, t_fractal *fractal);

int			key_handler(int keysym, t_fractal *fractal);
int			mouse_handler(int button, int x, int y, t_fractal *fractal);
int			close_handler(t_fractal *fractal);

#endif