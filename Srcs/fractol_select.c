/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_select.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhabaguh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 12:03:05 by jhabaguh          #+#    #+#             */
/*   Updated: 2022/02/25 13:00:45 by jhabaguh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strequ(char const *s1, char const *s2)
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

int	ft_strcmp(const char *s1, const char *s2)
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

void	menu(void)
{
	ft_putendl(NULL);
	ft_putendl("Type the fractol name after the program name.");
	ft_putendl("Example: ./fractol \"mandelbrot\"");
	ft_putendl("	1	mandelbrot");
	ft_putendl("	2	julia fixed");
	ft_putendl("	3	julia explore");
	ft_putendl("	4	burning ship");
	ft_putendl("Make sure your selection is enclosed in double quotes");
	ft_putendl(NULL);
	ft_putendl("In-program commands");
	ft_putendl("	1	To change the fractal you can press the number");
	ft_putendl("		corresponding to it.");
	ft_putendl("	2	In \"julia explore\" using the arrows changes");
	ft_putendl("		the real imaginery part pf the constant.");
	ft_putendl("	3	To reset, press the corresponding number.");
}

int	fractal_select(char *type, t_brain *brain)
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
		menu();
	return (brain->d.type);
}
