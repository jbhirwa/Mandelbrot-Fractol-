#include "fractol.h"

int close_win(int keycode, t_program *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx_pointer, vars->window);
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
