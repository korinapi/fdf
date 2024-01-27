/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpuiu <cpuiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:28:30 by cpuiu             #+#    #+#             */
/*   Updated: 2024/01/27 10:40:04 by cpuiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	initialize_axonometric(t_graphics_scene *fdf)
{
	double	x_scale;
	double	y_scale;

	x_scale = 2 * (double)(((double)(WINDOW_WIDTH)
				/ ((double)(max_x_axonometric(fdf) - min_x_axonometric(fdf)) \
					*3)));
	y_scale = 2 * (double)(((double)(WINDOW_HEIGHT)
				/ ((double)(max_y_axonometric(fdf) - min_y_axonometric(fdf)) \
					*3)));
	if (x_scale > y_scale)
		fdf->scaling_factor = y_scale;
	else
		fdf->scaling_factor = x_scale;
	fdf->margins_info.x_margin = (double)((double)1 / (double)6)
		*(WINDOW_WIDTH) - (min_x_axonometric(fdf) * fdf->scaling_factor);
	fdf->margins_info.y_margin = (double)((double)1 / (double)6) *WINDOW_HEIGHT
		- min_y_axonometric(fdf) * y_scale;
}

void	initialize_obliq(t_graphics_scene *fdf)
{
	double	x_scale;
	double	y_scale;

	x_scale = 2 * (double)(((double)(WINDOW_WIDTH) / ((double)(max_x_obliq(fdf)
						- min_x_obliq(fdf)) *3)));
	y_scale = 2 * (double)(((double)(WINDOW_HEIGHT) / ((double)(max_y_obliq(fdf)
						- min_y_obliq(fdf)) *3)));
	if (x_scale > y_scale)
		fdf->scaling_factor = y_scale;
	else
		fdf->scaling_factor = x_scale;
	fdf->margins_info.x_margin = (double)((double)1 / (double)6) *WINDOW_WIDTH
		- (min_x_obliq(fdf) * fdf->scaling_factor);
	fdf->margins_info.y_margin = (double)((double)1 / (double)6) *WINDOW_HEIGHT
		- min_y_obliq(fdf) * fdf->scaling_factor;
}

void	initialize_params(t_graphics_scene *fdf)
{
	if (fdf->projection_type == PROJ_AXO)
		initialize_axonometric(fdf);
	if (fdf->projection_type == PROJ_OBLIQUE)
		initialize_obliq(fdf);
}

void	initialize_scene(t_graphics_scene *fdf)
{
	fdf->window_width = WINDOW_WIDTH;
	fdf->window_height = WINDOW_HEIGHT;
	fdf->projection_type = PROJ_AXO;
	fdf->projection_info.obliq = M_PI / 3;
	fdf->projection_info.pitch = M_PI / 32;
	fdf->additional_altitude = 1;
	fdf->projection_info.yaw = 15 * (M_PI / 32);
	fdf->image_info.bytes_per_pixel = 0;
	fdf->image_info.bytes_order = 0;
	fdf->image_info.line_size = 0;
	fdf->projection_info.roll = 7 * (M_PI / 32);
	fdf->top_color[0] = 250;
	fdf->top_color[1] = 0;
	fdf->top_color[2] = 0;
	fdf->bottom_color[0] = 0;
	fdf->bottom_color[1] = 0;
	fdf->bottom_color[2] = 200;
	fdf->grab_info.is_active = 0;
	fdf->grab_info.is_figure_grabbed = 0;
	fdf->grab_info.is_alternate_figure = 0;
}
