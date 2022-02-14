#include "fractol.h"

int close_win(int keycode, t_brain *brain)
{
	if (keycode == 53)
	{
		mlx_destroy_window(brain->data.mlx, brain->data.win);
		exit(0);
	}

	return (0);
}

void	my_mlx_pixel_put(t_brain *brain, int x, int y, int color)
{
	char	*dst;

	dst = brain->data.addr + (y * brain->data.line_length + x * (brain->data.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int		mouse_hook(int mousecode, int x, int y, t_brain *brain)
{
	brain->m.re = x / (WIDTH / (brain->f.re_max - brain->f.re_min)) + brain->f.re_min;
    brain->m.im = y / (HEIGHT / (brain->f.im_max - brain->f.re_min)) + brain->f.im_min;
	zoom_control(mousecode, brain);
	return (0);
}

void        zoom_control(int key, t_brain *brain)
{
    double      *interp;

	if (key == 5 || key == 4)
	{
		interp = &brain->f.interp;//
		if (key == 5)    // zoom in
		{
			*interp = 1.0 / 1.03;
			apply_zoom(brain, brain->m.re, brain->m.im, *interp);
		}
		else if (key == 4)    // zoom out
		{
			*interp = 1.0 * 1.03;
			apply_zoom(brain, brain->m.re, brain->m.im, *interp);	
		}
		mlx_clear_window(brain->data.mlx, brain->data.win);
	//	mlx_destroy_window(brain->data.mlx, brain->data.win);
		Mandelbrot(brain);
		mlx_put_image_to_window(brain->data.mlx, brain->data.win, brain->data.img, 0, 0);//
	}
}

void        apply_zoom(t_brain *brain, double m_re, double m_im, double interp)
{
    brain->f.re_min = interpolate(m_re, brain->f.re_min, interp);
    brain->f.im_min = interpolate(m_im, brain->f.im_min, interp);
    brain->f.re_max = interpolate(m_re, brain->f.re_max, interp);
    brain->f.im_max = interpolate(m_im, brain->f.im_max, interp);
//printf("\n");
}

double      interpolate(double start, double end, double interp)
{
//	printf("%lf\n",start + ((end - start) * interp));
    return (start + ((end - start) * interp));
}

void		init_man(t_brain *brain)
{
	brain->f.re_max = 2.0;//
	brain->f.re_min = -2.0;//
	brain->f.im_min = -2.0;//
	brain->f.im_max = brain->f.im_min + (brain->f.re_max - brain->f.re_min) * HEIGHT / WIDTH;//	
}
