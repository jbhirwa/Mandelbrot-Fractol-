#include "fractol.h"

t_complex square(t_complex Zcmpx, t_complex Ccmpx)// z then c
{
	double	temp;
	
	temp = (Zcmpx.a * Zcmpx.a) - (Zcmpx.b * Zcmpx.b) + Ccmpx.a ;
	Zcmpx.b = 2.0 * Zcmpx.a * Zcmpx.b + Ccmpx.b;
	Zcmpx.a = temp;
	return(Zcmpx);
}

/*- x and y represent the pixel coordinates
 *- c and z are complex numbers each with an "a" and "b" component
 *- This formular "c.a = ((double)x -(window_ width/2))/(window_width/4)", 
 *converts the value of x into the "a" component of the complex number c.
 *- c.b is similar except, "c.b = ((double)y -(window_height/2))/(window_height/4)",
 *converts the value of y into the "b" component of the complex number c.
 *- The innermost while loop calculates whether the result of z is in the mandelbrot 
 *set after a number of iterations(50)
 */
void	Mandelbrot(t_data *img)
{
	int	x = 0;//
	int	y = 0;//
	t_complex	c;//
	t_complex	z;//

	while (x < 1080)
	{
		y = 0;
		while (y < 1080)
		{	
			c.a = ((double)x -(1080/2))/(1080/4);
			c.b = ((double)y -(1080/2))/(1080/4);
			z.a = 0.0;
			z.b = 0.0;
			int it = 0;
			while (it++ < 100 && (z.a * z.a) + (z.b * z.b) <= 4)
					z = square(z, c);
			if (it >= 99)//
				my_mlx_pixel_put(img, x, y, 0x00FF0000);
			y++;
		}
		x++;
	}
}
