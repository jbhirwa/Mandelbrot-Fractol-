#include "fractol.h"

int	main(void)
{
	t_data	img;
	t_program	vars;

	vars.mlx_pointer = mlx_init();
	vars.window = mlx_new_window(vars.mlx_pointer, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(vars.mlx_pointer, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	Mandelbrot(&img);
	mlx_put_image_to_window(vars.mlx_pointer, vars.window, img.img, 0, 0);
	mlx_hook(vars.window, 2, 1L<<0, close_win, &vars);
	mlx_loop(vars.mlx_pointer);
}
