#include "fractol.h"

int close_win(int keycode, t_brain *brain)
{
	if (keycode == 53)
	{
		mlx_destroy_window(brain->d.mlx, brain->d.win);
		exit(0);
	}

	return (0);
}

void	my_mlx_pixel_put(t_brain *brain, int x, int y, int color)
{
	char	*dst;

	dst = brain->d.addr + (y * brain->d.line_length + x * (brain->d.bpp / 8));
	*(unsigned int*)dst = color;
}
