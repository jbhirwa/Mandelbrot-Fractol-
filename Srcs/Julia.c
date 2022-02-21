#include "fractol.h"

void	Julia(t_brain *brain)
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
			brain->z.a = brain->f.re_min + (double)x * brain->f.re_factor;
			brain->z.b = brain->f.im_max - (double)y * brain->f.im_factor;
			brain->c.a = brain->m.re;
			brain->c.b = brain->m.im;
			int it = 0;
			while (it++ <= MAX_IT && (brain->z.a * brain->z.a) + (brain->z.b * brain->z.b) <= 4)
					brain->z = square(*brain);
			if (it >= MAX_IT)//
				my_mlx_pixel_put(brain, x, y, 0xFFFFFFFF);
			else
				//my_mlx_pixel_put(brain, x, y,400 + 0x0087cefa* it);
				my_mlx_pixel_put(brain, x, y, it - (int)brain->z.b*(int)brain->z.a);
		y++;
		}
	x++;
	}
}
