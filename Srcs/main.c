#include "fractol.h"


#include <mlx.h>
#include <stdlib.h>

#define LWST_VAL 200
#define HGHST_VAL 400

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_program
 {
	void	*mlx_pointer;
	void	*window;
	void	*img;
}				t_program;


int close(int keycode, t_program *vars)
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

int	main(void)
{
	t_data	img;
	t_program	vars;
	unsigned int colour = 0x00ff0000;

	vars.mlx_pointer = mlx_init();
	vars.window = mlx_new_window(vars.mlx_pointer, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(vars.mlx_pointer, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);


	for (int pos = LWST_VAL; pos <= HGHST_VAL; ++pos)
	{
		colour++;
   		// The bottom line
   		my_mlx_pixel_put(&img, pos, LWST_VAL, colour);
    	// The top line
    	my_mlx_pixel_put(&img, pos, HGHST_VAL, colour);
    	// The left line
    	my_mlx_pixel_put(&img, LWST_VAL, pos, colour);
    	// The right line
    	my_mlx_pixel_put(&img, HGHST_VAL, pos, colour);
	}
	mlx_put_image_to_window(vars.mlx_pointer, vars.window, img.img, 0, 0);
	mlx_hook(vars.window, 2, 1L<<0, close, &vars);
	mlx_loop(vars.mlx_pointer);
}


/*
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
*/
