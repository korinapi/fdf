/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_actions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpuiu <cpuiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:05:38 by cpuiu             #+#    #+#             */
/*   Updated: 2024/01/24 19:19:06 by cpuiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	update_axonometric(int keycode, t_graphics_scene *fdf)
{
	if (keycode == 123)
		fdf->projection_info.roll = fdf->projection_info.roll + M_PI / 64;
	if (keycode == 124)
		fdf->projection_info.roll = fdf->projection_info.roll - M_PI / 64;
	if (keycode == 125)
		fdf->projection_info.yaw = fdf->projection_info.yaw + M_PI / 64;
	if (keycode == 126)
		fdf->projection_info.yaw = fdf->projection_info.yaw - M_PI / 64;
}

int	key(int keycode, t_graphics_scene *fdf)
{
	if (fdf->projection_type == PROJ_AXO)
		update_axonometric(keycode, fdf);
	if (fdf->projection_type == PROJ_OBLIQUE)
	{
		if (keycode == 123)
			fdf->projection_info.obliq = fdf->projection_info.obliq + M_PI / 32;
		if (keycode == 124)
			fdf->projection_info.obliq = fdf->projection_info.obliq - M_PI / 32;
	}
	color_fig_image(fdf);
	return (0);
}

int	key_hook(int keycode, t_graphics_scene *fdf)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 31 && fdf->projection_type != PROJ_OBLIQUE)
	{
		fdf->projection_type = PROJ_OBLIQUE;
		initialize_params(fdf);
		color_fig_image(fdf);
	}
	if (keycode == 34 && fdf->projection_type != PROJ_AXO)
	{
		fdf->projection_type = PROJ_AXO;
		initialize_params(fdf);
		color_fig_image(fdf);
	}
	return (0);
}
