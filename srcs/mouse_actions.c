/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpuiu <cpuiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:29:07 by cpuiu             #+#    #+#             */
/*   Updated: 2024/01/24 19:23:01 by cpuiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mouse_released(int key, int x, int y, t_graphics_scene *fdf)
{
	int	i;

	i = x;
	i = y;
	if (key == 1)
	{
		fdf->grab_info.is_active = 0;
		fdf->grab_info.is_figure_grabbed = 0;
	}
	else
		fdf->grab_info.is_alternate_figure = 0;
	return (0);
}

void	motion_top(int x, int y, t_graphics_scene *fdf)
{
	if (fdf->grab_info.is_figure_grabbed == 1)
	{
		if (fdf->projection_type == PROJ_AXO)
		{
			fdf->projection_info.yaw = fdf->projection_info.yaw
				+ ((y - fdf->grab_info.grabbed_figure_y) * (M_PI / 1024));
			fdf->grab_info.grabbed_figure_y = y;
			fdf->projection_info.roll = fdf->projection_info.roll
				+ ((x - fdf->grab_info.grabbed_figure_x) * (M_PI / 1024));
			fdf->grab_info.grabbed_figure_x = x;
		}
		if (fdf->projection_type == PROJ_OBLIQUE)
		{
			fdf->projection_info.obliq = fdf->projection_info.obliq
				+ ((x - fdf->grab_info.grabbed_figure_x) * (M_PI / 512));
			fdf->grab_info.grabbed_figure_x = x;
		}
		color_fig_image(fdf);
	}
}

int	motion(int x, int y, t_graphics_scene *fdf)
{
	motion_top(x, y, fdf);
	if (fdf->grab_info.is_active == 1)
	{
		if (x >= 160)
			x = 160;
		if (x < 10)
			x = 10;
		*(fdf->grab_info.grabbed_values) = ((x - 10) * 255) / 150;
		color_fig_image(fdf);
	}
	if (fdf->grab_info.is_alternate_figure)
	{
		fdf->margins_info.y_margin = fdf->margins_info.y_margin
			+ ((y - fdf->grab_info.grabbed_figure_y));
		fdf->grab_info.grabbed_figure_y = y;
		fdf->margins_info.x_margin = fdf->margins_info.x_margin
			+ ((x - fdf->grab_info.grabbed_figure_x));
		fdf->grab_info.grabbed_figure_x = x;
		color_fig_image(fdf);
	}
	return (0);
}
