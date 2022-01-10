#include "mlx.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct	s_program
 {
	void	*mlx;
	void	*win;
	void	*img;
}				t_program;

int	mouse_zoom(int keycode, int x, int y)
{
	printf("Keycode: %d\nx: %d\ny: %d\n", keycode, x, y);
	return (0);
}

int close(int keycode, t_program *vars)
{
	static int hor = 0;
	static int ver = 0;
	if(keycode == 123 || keycode == 124 || keycode == 125 || keycode == 126)
		mlx_clear_window(vars->mlx, vars->win);
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	if (keycode == 124)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, hor +=10, ver);
	if (keycode == 123)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, hor -=10, ver);
	if (keycode == 126)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, hor, ver -=10);
	if (keycode == 125)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, hor, ver +=10);
	return (0);
}

int main(void)
{
	t_program vars;
	char	*file = "./Srcs/sample.xpm";
	int		img_width;
	int		img_height;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1000, 1000, "keyboard");
	vars.img = mlx_xpm_file_to_image(vars.mlx, file, &img_width, &img_height);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 0, 0);
	mlx_hook(vars.win, 2, 1L<<0, close, &vars);
	mlx_mouse_hook(vars.win, &mouse_zoom, NULL);
	mlx_loop(vars.mlx);	

}
