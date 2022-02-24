#include "fractol.h"

t_complex square(t_brain brain)// z then c
{
	double	temp;
	temp = (brain.z.a * brain.z.a) - (brain.z.b * brain.z.b) + brain.c.a;
	if (brain.d.type == 4)
		brain.z.b = fabs(2.0 * brain.z.a *brain.z.b) + brain.c.b;
	else
		brain.z.b = 2.0 * brain.z.a *brain.z.b + brain.c.b;
	brain.z.a = temp;
	return(brain.z);
}

void	fractol(t_brain *brain)
{
	int	x = 0;//
	int	y = 0;//
	brain->f.re_factor = (brain->f.re_max - brain->f.re_min) / (WIDTH- 1);
	brain->f.im_factor = (brain->f.im_max - brain->f.im_min) / (HEIGHT - 1);
	if (brain->d.type == 2)
		fixed_julia(brain);
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
	//	while (brain->t.start < brain->t.end)
		{	
			init_c_and_z(brain, x, y);
			int it = 0;
			while (it++ <= MAX_IT && (brain->z.a * brain->z.a) + (brain->z.b * brain->z.b) <= 4)
					brain->z = square(*brain);
			if (it >= MAX_IT)//
				my_mlx_pixel_put(brain, x, y, 0xFFFFFFFF);
			else
				my_mlx_pixel_put(brain, x, y,400 + 0x0087cefa* it);
			//	my_mlx_pixel_put(brain, x, y, it - (int)brain->z.b*(int)brain->z.a);
		y++;
		}
	x++;
	}
}
