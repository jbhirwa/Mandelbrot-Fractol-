#ifndef FRACTOL_H
# define FRACTOL_H

# define MAX_IT 100
# define HEIGHT 1080
# define WIDTH 1080
# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "mlx.h"

typedef struct	s_complex
{
	double	a;
	double	b;
}				t_complex;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_program
 {
	void	*mlx_pointer;
	void	*window;
	void	*img;
}				t_program;

typedef struct	s_fractal_init
{
	double re_max;
	double re_min;
	double im_min;
	double im_max;
	double re_factor;
	double im_factor;
}				t_fractal_init;

typedef struct	s_mouse
{
	double	re;
	double	im;
}				t_mouse;

typedef struct	s_brain
{
	t_complex		fcomplex;
	t_data			data;
	t_program		program;
	t_fractal_init	f;
}				t_brain;

int close_win(int keycode, t_program *vars);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	Mandelbrot(t_data *img);
t_complex square(t_complex Zcmpx, t_complex Ccmpx);

#endif
