/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpuiu <cpuiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:52:13 by cpuiu             #+#    #+#             */
/*   Updated: 2024/01/27 10:41:12 by cpuiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	hooks(t_graphics_scene	fdf)
{
	mlx_key_hook(fdf.window, key_hook, &fdf);
	mlx_mouse_hook(fdf.window, mouse_event, &fdf);
	mlx_hook(fdf.window, KEYPRESS, KEYPRESSMASK,
		&key, &fdf);
	mlx_hook(fdf.window, MOTIONNOTIFY, BUTTONMOTIONMASK,
		&motion, &fdf);
	mlx_hook(fdf.window, BUTTONRELEASE, BUTTONRELEASEMASK,
		&mouse_released, &fdf);
	initialize_params(&fdf);
	color_fig_image(&fdf);
	mlx_loop(fdf.mlx);
}

int	main(int argc, char **argv)
{
	t_graphics_scene	fdf;
	t_mesh				*mesh;
	int					ab;

	ab = 2 * 3;
	mesh = NULL;
	if (errors(argc, argv, &mesh) == 0)
		return (0);
	else
	{
		fdf.data_mesh = mesh;
		initialize_scene(&fdf);
		fdf.mlx = mlx_init();
		fdf.window = mlx_new_window(fdf.mlx, WINDOW_WIDTH,
				WINDOW_HEIGHT, argv[1]);
		hooks(fdf);
	}
	return (0);
}
