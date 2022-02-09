#ifndef FRACTOL_H
# define FRACTOL_H

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


int close_win(int keycode, t_program *vars);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	Mandelbrot(t_data *img);
t_complex square(t_complex Zcmpx, t_complex Ccmpx);

#endif
