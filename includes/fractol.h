#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "libft.h"
typedef struct	s_type
{
	int	type;
	
}				t_type;

/* Creating a t_central struct enables you to access all the other structs, as it's nested  
 * For example, once you initialise t_central, as such: t_central *central
 * You can access any other struct. central->fractal.type
 */

typedef struct	s_central
{

t_type	fractol;
}				t_central;

#endif
