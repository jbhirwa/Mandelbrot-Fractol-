#include "fractol.h"

int	main(void)
{
	t_brain brain;
	t_program	vars;

	vars.mlx_pointer = mlx_init();
	vars.window = mlx_new_window(vars.mlx_pointer, WIDTH, HEIGHT, "Hello world!");
	brain.data.img = mlx_new_image(vars.mlx_pointer, WIDTH, HEIGHT);
	brain.data.addr = mlx_get_data_addr(brain.data.img, &brain.data.bits_per_pixel, &brain.data.line_length,
								&brain.data.endian);
	Mandelbrot(&brain);
	mlx_put_image_to_window(vars.mlx_pointer, vars.window, brain.data.img, 0, 0);
	mlx_hook(vars.window, 2, 1L<<0, close_win, &vars);
	mlx_loop(vars.mlx_pointer);
}
