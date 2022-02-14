#include "fractol.h"

t_complex square(t_brain brain)// z then c
{
	double	temp;
	temp = (brain.z.a * brain.z.a) - (brain.z.b * brain.z.b) + brain.c.a;
	brain.z.b = 2.0 * brain.z.a *brain.z.b + brain.c.b;
	brain.z.a = temp;
	return(brain.z);
}

void	Mandelbrot(t_brain *brain)
{
	int	x = 0;//
	int	y = 0;//
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
			while (it++ <= MAX_IT && (brain->z.a * brain->z.a) + (brain->z.b * brain->z.b) <= 4)
					brain->z = square(*brain);
			if (it >= MAX_IT)//
				my_mlx_pixel_put(brain, x, y, 0xFFFFFFFF);
			else
				//my_mlx_pixel_put(brain, x, y, it*100);			//normal
				//my_mlx_pixel_put(brain, x, y, (it + y)*1000);		//2/5
				//my_mlx_pixel_put(brain, x, y, (it + y)*x);			//3/5
				//my_mlx_pixel_put(brain, x, y, (it*y)*x);			//3/5
				//my_mlx_pixel_put(brain, x, y, it*(int)brain->z.a);			//4/5
					//my_mlx_pixel_put(brain, x, y, it*(int)brain->z.a*1000);
					//my_mlx_pixel_put(brain, x, y, it*(int)brain->z.a*(int)brain->z.b*1000);
					//my_mlx_pixel_put(brain, x, y, ((it*(int)brain->z.a)+(int)brain->z.b)*1000);
					my_mlx_pixel_put(brain, x, y, it - (int)brain->z.b*(int)brain->z.a);
				//my_mlx_pixel_put(brain, x, y, (it*x)+y);			//2/5
				//my_mlx_pixel_put(brain, x, y, ((it*x)+y)*1000);		//3/5
			y++;
		}
		x++;
	}
}
