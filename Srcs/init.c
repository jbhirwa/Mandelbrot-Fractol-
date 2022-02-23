#include "fractol.h"

void		init_fractol(t_brain *brain)
{
	brain->f.re_max = 2.0;//
	brain->f.re_min = -2.0;//
	brain->f.im_min = -2.0;//
	brain->f.im_max = brain->f.im_min + (brain->f.re_max - brain->f.re_min) * HEIGHT / WIDTH;
	if (brain->d.type == 3)
	{	
		brain->m.re = -0.70176;
		brain->m.im = -0.38842;
//−0.835 − 0.2321
	}
}

void fixed_julia(t_brain *brain)
{
	brain->m.re = -0.835;//
	brain->m.im = -0.2321;//	
}

void init_c_and_z(t_brain *brain, int x, int y)
{
	if (brain->d.type == 1 || brain->d.type == 4)
	{
		brain->c.a = brain->f.re_min + (double)x * brain->f.re_factor;
		brain->c.b = brain->f.im_max - (double)y * brain->f.im_factor;
		brain->z.a = 0.0;
		brain->z.b = 0.0;
	}		
	if (brain->d.type == 2 || brain->d.type == 3)
	{
		brain->z.a = brain->f.re_min + (double)x * brain->f.re_factor;
		brain->z.b = brain->f.im_max - (double)y * brain->f.im_factor;
		brain->c.a = brain->m.re;
		brain->c.b = brain->m.im;
	}
}
