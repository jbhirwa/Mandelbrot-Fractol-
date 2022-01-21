#include "fractol.h"
#include <stdlib.h>
#include <stdio.h>

static int	select_fractol(char *argv, t_central *central) 
{
	central->fractol.type = 0;
	if (ft_strequ(ft_str_to_lowercase(argv), "mandelbrot"))
		central->fractol.type = 1;
	printf("%d \n\n", central->fractol.type);
	return(central->fractol.type);
}

int main(int argc, char **argv)
{
	t_central	*central;
	if (argc == 2)	
	{
		if (!(central = (t_central *)malloc(sizeof(central))))
			printf("unsuccess\n\n");
		if (!(select_fractol(argv[1], central)))
			printf("try again\n\n");
	}
	return (0);
}
