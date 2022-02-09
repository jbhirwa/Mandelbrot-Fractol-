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

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
