/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_controls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhabaguh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 11:53:34 by jhabaguh          #+#    #+#             */
/*   Updated: 2022/02/25 13:15:09 by jhabaguh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_hook(int mousecode, int x, int y, t_brain *brain)
{
	brain->m.re = x / (WIDTH / (brain->f.re_max - brain->f.re_min))
		+ brain->f.re_min;
	brain->m.im = y / (HEIGHT / (brain->f.im_max - brain->f.re_min))
		+ brain->f.im_min;
	zoom_control(mousecode, brain);
	return (0);
}

void	zoom_control(int key, t_brain *brain)
{
	double	*interp;

	if (key == 5 || key == 4)
	{
		interp = &brain->f.interp;
		if (key == 5)
		{
			*interp = 1.0 / 1.03;
			apply_zoom(brain, brain->m.re, brain->m.im, *interp);
		}
		else if (key == 4)
		{
			*interp = 1.0 * 1.03;
			apply_zoom(brain, brain->m.re, brain->m.im, *interp);
		}
		mlx_clear_window(brain->d.mlx, brain->d.win);
		fractol(brain);
		mlx_put_image_to_window(brain->d.mlx, brain->d.win,
			brain->d.img, 0, 0);
	}
}

void	apply_zoom(t_brain *brain, double m_re, double m_im, double interp)
{
	brain->f.re_min = interpolate(m_re, brain->f.re_min, interp);
	brain->f.im_min = interpolate(m_im, brain->f.im_min, interp);
	brain->f.re_max = interpolate(m_re, brain->f.re_max, interp);
	brain->f.im_max = interpolate(m_im, brain->f.im_max, interp);
}

double	interpolate(double start, double end, double interp)
{
	return (start + ((end - start) * interp));
}

size_t	ft_strlen(const char *s)
{
	size_t len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}
