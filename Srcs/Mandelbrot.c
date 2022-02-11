#include "fractol.h"

t_complex square(t_brain brain)// z then c
{
	double	temp;
	temp = (brain.z.a * brain.z.a) - (brain.z.b * brain.z.b) + brain.c.a;
	brain.z.b = 2.0 * brain.z.a *brain.z.b + brain.c.b;
	brain.z.a = temp;
	return(brain.z);
}

/*- x and y represent the pixel coordinates
 *- c and z are complex numbers each with an "a" and "b" component
 *- This formular "c.a = ((double)x -(window_ width/2))/(window_width/4)", 
 *converts the value of x into the "a" component of the complex number c.
 *- c.b is similar except, "c.b = ((double)y -(window_height/2))/(window_height/4)",
 *converts the value of y into the "b" component of the complex number c.
 *- The innermost while loop calculates whether the result of z is in the mandelbrot 
 *set after a number of iterations(50)
 */
void	Mandelbrot(t_brain *brain)
{
	int	x = 0;//
	int	y = 0;//
	brain->f.re_max = 2.0;
	brain->f.re_min = -2.0;
	brain->f.im_min = -2.0;
	brain->f.im_max = brain->f.im_min + (brain->f.re_max - brain->f.re_min) * HEIGHT / WIDTH;
	brain->f.re_factor = (brain->f.re_max - brain->f.re_min) / (WIDTH- 1);
	brain->f.im_factor = (brain->f.im_max - brain->f.im_min) / (HEIGHT - 1);
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{		

			brain->c.a = brain->f.re_min + (double)x * brain->f.re_factor;
			brain->c.b = brain->f.im_max - (double)y * brain->f.im_factor;
			brain->z.a = 0.0;
			brain->z.b = 0.0;
			int it = 0;
			while (it++ < MAX_IT && (brain->z.a * brain->z.a) + (brain->z.b * brain->z.b) <= 4)
					brain->z = square(*brain);
			if (it >= MAX_IT - 1)//
				my_mlx_pixel_put(brain, x, y, 0xFFFFFFFF);
			else
				my_mlx_pixel_put(brain, x, y, it*100);
			y++;
		}
		x++;
	}
}
