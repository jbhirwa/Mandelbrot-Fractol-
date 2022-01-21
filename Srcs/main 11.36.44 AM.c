#include <mlx.h>
#include <stdlib.h>
#include <math.h>

#define LWST_VAL 200
#define HGHST_VAL 600

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
		int x = pos;
		int y = LWST_VAL;
		if ((x + y)%2 == 0)
		{
			y += (rand()%(100 - 1 + 1)) + 1;
			x += (rand()%(100 - 1 + 1)) + 1;
   			my_mlx_pixel_put(&img, x, y, 0x00FF0000 + (rand()%(767 - 0 + 0)) + 0);
		}
		else 
			my_mlx_pixel_put(&img, x, y, 0x0000FF00);
    	}	
	
	mlx_put_image_to_window(vars.mlx_pointer, vars.window, img.img, 0, 0);
	mlx_hook(vars.window, 2, 1L<<0, close, &vars);
	mlx_loop(vars.mlx_pointer);
}
