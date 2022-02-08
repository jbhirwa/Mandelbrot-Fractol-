#include <stdio.h>
#include <mlx.h>
#include <stdlib.h>

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

typedef struct	s_complex
{
	double	a;
	double	b;
}				t_complex;

t_complex square(t_complex cmpx, t_complex Zcmpx)
{
	double	temp;
	
	temp = (cmpx.a * cmpx.a) - (cmpx.b * cmpx.b) + Zcmpx.a ;
	cmpx.b = 2.0 * cmpx.a * cmpx.b + Zcmpx.b;
	cmpx.a = temp;
	return(cmpx);
}

void	Mandelbrot(t_data *img)
{
	int	x = 0;//
	int	y = 0;//
	t_complex	c;//
	t_complex	z;//

	for (x = 0; x < 1080; x++)	
	{
		for (y = 0; y < 1080; y++)
		{	
			c.a = ((double)x -(1080/2))/(1080/4);		//a
			c.b = ((double)y -(1080/2))/(1080/4);	//b
			z.a = 0.0;
			z.b = 0.0;
			int it = 0;
			while (it++ < 50 && (z.a * z.a) + (z.b * z.b) <= 4)
					z = square(z, c);
			if (it >= 49)//
				my_mlx_pixel_put(img, x, y, 0x00FF0000);
		}
	}
	//return (it);
}

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
	mlx_hook(vars.window, 2, 1L<<0, close, &vars);
	mlx_loop(vars.mlx_pointer);
}
