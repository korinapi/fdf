/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpuiu <cpuiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:50:27 by cpuiu             #+#    #+#             */
/*   Updated: 2024/01/24 20:02:56 by cpuiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	grab_tab(t_graphics_scene *fdf, int tab[3], int index, int val)
{
	fdf->grab_info.is_active = 1;
	tab[index] = val;
	fdf->grab_info.grabbed_values = &(tab[index]);
}

void	grab_figure(int key, int x, int y, t_graphics_scene *fdf)
{
	if (key == 1)
	{
		fdf->grab_info.is_figure_grabbed = 1;
		fdf->grab_info.grabbed_figure_x = x;
		fdf->grab_info.grabbed_figure_y = y;
	}
	if (key == 2)
	{
		fdf->grab_info.is_alternate_figure = 1;
		fdf->grab_info.grabbed_figure_x = x;
		fdf->grab_info.grabbed_figure_y = y;
	}
}

int	mouse_event_funct_projection(int key, int x, int y, t_graphics_scene *fdf)
{
	if (x > 25 && x < 175 && y > 85 && y < 135)
	{
		fdf->projection_type = PROJ_AXO;
		initialize_params(fdf);
	}
	if (x > 25 && x < 175 && y > 160 && y < 210)
	{
		fdf->projection_type = PROJ_OBLIQUE;
		initialize_params(fdf);
	}
	if (x < WINDOW_WIDTH && x > 200 && y < WINDOW_HEIGHT && y > 0)
		grab_figure(key, x, y, fdf);
	return (0);
}

int	mouse_event(int key, int x, int y, t_graphics_scene *fdf)
{
	mouse_event_funct_projection(key, x, y, fdf);
	if (key == 4)
	{
		if (fdf->scaling_factor > 1.0)
			fdf->scaling_factor -= 1.0;
	}
	if (key == 5)
		fdf->scaling_factor += 1.0;
	color_fig_image(fdf);
	return (0);
}
