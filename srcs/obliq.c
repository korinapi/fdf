/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obliq.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpuiu <cpuiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 11:51:53 by cpuiu             #+#    #+#             */
/*   Updated: 2024/01/24 13:32:26 by cpuiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	vertical_obliq(int x_index, int y_index,
		t_graphics_scene *fdf, int *data)
{
	double	z;

	z = fdf->data_mesh->mesh[y_index + 1][x_index];
	fdf->end_x = fdf->margins_info.x_margin
		+ (((x_index + (((double)1 / (double)2)
						* (double)z * fdf->additional_altitude)
					* cos(fdf->projection_info.obliq))) * fdf->scaling_factor);
	fdf->end_y = fdf->margins_info.y_margin
		+ (((y_index + 1 + (((double)1 / (double)2) * (double)z
						* fdf->additional_altitude)
					* sin(fdf->projection_info.obliq))) * fdf->scaling_factor);
	fdf->end_z = z;
	draw_line_image(fdf, data);
}

void	horizontal_obliq(int x_index, int y_index,
		t_graphics_scene *fdf, int *data)
{
	double	z;

	z = fdf->data_mesh->mesh[y_index][x_index + 1];
	fdf->end_x = fdf->margins_info.x_margin
		+ (((x_index + 1 + (((double)1 / (double)2) * (double)z
						* fdf->additional_altitude)
					* cos(fdf->projection_info.obliq)))
			* fdf->scaling_factor);
	fdf->end_y = fdf->margins_info.y_margin
		+ (((y_index + (((double)1 / (double)2) * (double)z
						* fdf->additional_altitude)
					* sin(fdf->projection_info.obliq)))
			* fdf->scaling_factor);
	fdf->end_z = z;
	draw_line_image(fdf, data);
}

void	lines_obliq_image(int x_index, int y_index,
		t_graphics_scene *fdf, int *data)
{
	double	x;
	double	y;
	double	z;

	x = x_index;
	y = y_index;
	z = fdf->data_mesh->mesh[y_index][x_index];
	fdf->start_x = fdf->margins_info.x_margin
		+ (((x + (((double)1 / (double)2) * (double)z
						* fdf->additional_altitude)
					* cos(fdf->projection_info.obliq))) * fdf->scaling_factor);
	fdf->start_y = fdf->margins_info.y_margin
		+ (((y + (((double)1 / (double)2) * (double)z
						* fdf->additional_altitude)
					* sin(fdf->projection_info.obliq))) * fdf->scaling_factor);
	fdf->end_z = z;
	if (y_index < fdf->data_mesh->mesh_height - 1)
		vertical_obliq(x_index, y_index, fdf, data);
	if (x_index < fdf->data_mesh->mesh_width - 1)
		horizontal_obliq(x_index, y_index, fdf, data);
}
