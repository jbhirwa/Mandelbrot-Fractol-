/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Make_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhabaguh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 12:29:24 by jhabaguh          #+#    #+#             */
/*   Updated: 2022/02/25 12:30:17 by jhabaguh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Make_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhabaguh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 12:12:21 by jhabaguh          #+#    #+#             */
/*   Updated: 2022/02/25 12:29:16 by jhabaguh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	square(t_brain brain)
{
	double	temp;

	temp = (brain.z.a * brain.z.a) - (brain.z.b * brain.z.b) + brain.c.a;
	if (brain.d.type == 4)
		brain.z.b = fabs(2.0 * brain.z.a * brain.z.b) + brain.c.b;
	else
		brain.z.b = 2.0 * brain.z.a * brain.z.b + brain.c.b;
	brain.z.a = temp;
	return (brain.z);
}

void	fractol(t_brain *brain)
{
	brain->f.x = 0;
	brain->f.re_factor = (brain->f.re_max - brain->f.re_min) / (WIDTH - 1);
	brain->f.im_factor = (brain->f.im_max - brain->f.im_min) / (HEIGHT - 1);
	if (brain->d.type == 2)
		fixed_julia(brain);
	while (brain->f.x < WIDTH)
	{
		brain->f.y = 0;
		while (brain->f.y < HEIGHT)
		{
			init_c_and_z(brain);
			brain->f.it = 0;
			while (brain->f.it++ <= MAX_IT && (brain->z.a * brain->z.a)
				+ (brain->z.b * brain->z.b) <= 4)
				brain->z = square(*brain);
			if (brain->f.it >= MAX_IT)
				my_mlx_pixel_put(brain, brain->f.x, brain->f.y, 0xFFFFFFFF);
			else
				my_mlx_pixel_put(brain, brain->f.x, brain->f.y, 400
					+ 0x0087cefa * brain->f.it);
		brain->f.y++;
		}
	brain->f.x++;
	}
}
