#include "fractol.h"

int		ft_strequ(char const *s1, char const *s2)
{
	if (s1 && s2)
		if (!ft_strcmp(s1, s2))
			return (1);
	return (0);
}

char	*ft_str_to_lowcase(char *str)
{
	int		i;

	i = 0;
	while (str[i++])
		if (str[i - 1] >= 'A' && str[i - 1] <= 'Z')
			str[i - 1] += 32;
	return (str);
}

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*us1;
	unsigned char	*us2;

	us1 = (unsigned char *)s1;
	us2 = (unsigned char *)s2;
	while (*us1 && (*us1 == *us2))
	{
		us1 += 1;
		us2 += 1;
	}
	return (*us1 - *us2);
}

void menu(void)
{
	printf("\nTo select a fractal, type the fractol name after the program name.\n");
	printf("Example: ./fractol \"mandelbrot\"\n");
	printf("\t1	mandelbrot\n");
	printf("\t2	julia fixed\n");
	printf("\t3	julia explore\n");
	printf("\t4	burning ship\n");
	printf("Make sure your selection is enclosed in double quotes\n\n");
	printf("In-program commands\n");
	printf("\t1\tTo change the fractal you can press the number\n\t\tcorresponding to it.\n");
	printf("\t2\tIn \"julia explore\" using the arrows changes\n\t\tthe real imaginery part pf the constant.\n");
	printf("\t3\tTo reset, press the corresponding number.\n");
}

int fractal_select(char *type, t_brain *brain)
{
	if (ft_strequ(ft_str_to_lowcase(type), "mandelbrot"))
		brain->d.type = 1;
	else if (ft_strequ(ft_str_to_lowcase(type), "julia fixed"))
		brain->d.type = 2;
	else if (ft_strequ(ft_str_to_lowcase(type), "julia explore"))
		brain->d.type = 3;
	else if (ft_strequ(ft_str_to_lowcase(type), "burning ship"))
		brain->d.type = 4;
	else
	{
		menu();

	}
	return(brain->d.type);	
}
