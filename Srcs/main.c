#include "fractol.h"

int	main(void)
{
	t_brain brain;

	brain.data.mlx = mlx_init();//
	brain.data.win = mlx_new_window(brain.data.mlx, WIDTH, HEIGHT, "Hello world!");//
	brain.data.img = mlx_new_image(brain.data.mlx, WIDTH, HEIGHT);
	brain.data.addr = mlx_get_data_addr(brain.data.img, &brain.data.bits_per_pixel, &brain.data.line_length, &brain.data.endian);
	init_man(&brain);
	Mandelbrot(&brain);
	mlx_put_image_to_window(brain.data.mlx, brain.data.win, brain.data.img, 0, 0);//
	mlx_hook(brain.data.win, 2, 1L<<0, close_win, &brain);//
	mlx_mouse_hook(brain.data.win, mouse_hook, &brain);
	mlx_loop(brain.data.mlx);
}
