/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhabaguh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 12:31:26 by jhabaguh          #+#    #+#             */
/*   Updated: 2022/02/25 12:35:26 by jhabaguh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_brain	brain;

	if (argc == 2)
	{
		fractal_select(argv[1], &brain);
		if (brain.d.type >= 1)
		{
			brain.d.mlx = mlx_init();
			brain.d.win = mlx_new_window(brain.d.mlx, WIDTH, HEIGHT,
					"Fract-ol");
			brain.d.img = mlx_new_image(brain.d.mlx, WIDTH, HEIGHT);
			brain.d.addr = mlx_get_data_addr(brain.d.img, &brain.d.bpp,
					&brain.d.line_length, &brain.d.endian);
			reset_and_run(&brain);
			mlx_hook(brain.d.win, 2, 1L << 0, close_win, &brain);
			mlx_mouse_hook(brain.d.win, mouse_hook, &brain);
			mlx_loop(brain.d.mlx);
		}	
	}
	else
		menu();
	return (0);
}
