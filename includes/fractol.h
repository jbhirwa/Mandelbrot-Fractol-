#ifndef FRACTOL_H
# define FRACTOL_H

# define MAX_IT 100
# define THREADS 8
# define HEIGHT 1080
# define WIDTH 1080
# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include "mlx.h"
# include "libft.h"

typedef struct	s_complex
{
	double	a;
	double	b;
}				t_complex;

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*mlx;//
	void	*win;//
}				t_data;

typedef struct	s_fractal_init
{
	double		re_max;
	double		re_min;
	double		im_min;
	double		im_max;
	double		re_factor;
	double		im_factor;
	double		interp;
}				t_fractal_init;

typedef struct	s_mouse
{
	double	re;
	double	im;
}				t_mouse;

typedef struct	s_thread
{
	int	start;
	int end;
}				t_thread;

typedef struct	s_brain
{
	t_complex		z;
	t_complex		c;
	t_data			data;
	t_fractal_init	f;
	t_mouse			m;
	t_thread		t;
}				t_brain;

void		init_man(t_brain *brain);
int			close_win(int keycode, t_brain *brain);
void		my_mlx_pixel_put(t_brain *brain, int x, int y, int color);
void		Mandelbrot(t_brain *brain);
t_complex	square(t_brain brain);
int			mouse_hook(int mousecode, int x, int y, t_brain *brain);
void        zoom_control(int key, t_brain *brain);
double      interpolate(double start, double end, double interp);
void        apply_zoom(t_brain *brain, double m_re, double m_im, double interp);
//void		*ft_memcpy(void *dst, const void *src, size_t n);
void	Julia(t_brain *brain);
void		init_julia(t_brain *brain);


#endif
