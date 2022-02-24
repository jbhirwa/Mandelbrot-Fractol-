#include "fractol.h"

int close_win(int keycode, t_brain *brain)
{
	if((keycode == 123 || keycode == 124 || keycode == 125 || keycode == 126) && brain->d.type == 3)
		mlx_clear_window(brain->d.mlx, brain->d.win);
	if (keycode == 53)
	{
		mlx_destroy_window(brain->d.mlx, brain->d.win);
		exit(0);
	}
	if (keycode == 18)
		brain->d.type = 1;
	if (keycode == 19)
		brain->d.type = 2;
	if (keycode == 20)
		brain->d.type = 3;
	if (keycode == 21)
		brain->d.type = 4;
	if (keycode == 18 || keycode == 19 || keycode == 20 || keycode == 21)
	{
		mlx_clear_window(brain->d.mlx, brain->d.win);
		reset_and_run(brain);
	}
	if (brain->d.type == 3)
	{
		if (keycode == 123)
			brain->m.im -= 0.01;
		if (keycode == 124)
			brain->m.im += 0.01;
		if (keycode == 125)
			brain->m.re += 0.01;
		if (keycode == 126)
			brain->m.re -= 0.01;
	//	reset_and_run(brain);
		fractol(brain);
		mlx_put_image_to_window(brain->d.mlx, brain->d.win, brain->d.img, 0, 0);//		
	}
	return (0);
}

void	my_mlx_pixel_put(t_brain *brain, int x, int y, int color)
{
	char	*dst;

	dst = brain->d.addr + (y * brain->d.line_length + x * (brain->d.bpp / 8));
	*(unsigned int*)dst = color;
}

void reset_and_run(t_brain *brain)
{
	init_fractol(brain);
	//t_fractol(brain);
	fractol(brain);
	mlx_put_image_to_window(brain->d.mlx, brain->d.win, brain->d.img, 0, 0);//	
}
