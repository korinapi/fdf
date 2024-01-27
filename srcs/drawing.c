/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpuiu <cpuiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:04:38 by cpuiu             #+#    #+#             */
/*   Updated: 2024/01/23 21:21:29 by cpuiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	is_active_line(t_graphics_scene *fdf)
{
	if (fdf->start_x < 0 && fdf->end_x < 0)
		return (0);
	if (fdf->start_x > WINDOW_WIDTH && fdf->end_x > WINDOW_WIDTH)
		return (0);
	if (fdf->start_y < 0 && fdf->end_y < 0)
		return (0);
	if (fdf->start_y > WINDOW_HEIGHT && fdf->end_y > WINDOW_HEIGHT)
		return (0);
	return (1);
}

int	draw_line_image(t_graphics_scene *fdf, int *data)
{
	if (is_active_line(fdf))
		draw_line_tierce(fdf, data);
	return (0);
}

void	draw_vertical_line(int x_index, int y_index,
					t_graphics_scene *fdf, int *data)
{
	double	z;

	z = fdf->data_mesh->mesh[y_index + 1][x_index];
	fdf->end_z = z;
	fdf->end_x = fdf->margins_info.x_margin + ((cos(fdf->projection_info.roll)
				* (x_index -(fdf->data_mesh->mesh_width - 1) / 2))
			- (sin(fdf->projection_info.roll) * (y_index + 1
					- (fdf->data_mesh->mesh_height - 1) / 2)))
		* fdf->scaling_factor;
	fdf->end_y = fdf->margins_info.y_margin - (((-sin(fdf->projection_info.roll)
					* sin(fdf->projection_info.yaw) * (x_index
						- (fdf->data_mesh->mesh_width - 1) / 2))
				- (cos(fdf->projection_info.roll)
					* sin(fdf->projection_info.yaw)
					* (y_index + 1 - (fdf->data_mesh->mesh_height - 1) / 2))
				+ (cos(fdf->projection_info.yaw) * (z * fdf->additional_altitude
						- (fdf->data_mesh->altitude + 1) / 2)))
			* fdf->scaling_factor);
	draw_line_image(fdf, data);
}

void	draw_horizontal_line(int x_index, int y_index,
							t_graphics_scene *fdf, int *data)
{
	double	z;

	z = fdf->data_mesh->mesh[y_index][x_index + 1];
	fdf->end_z = z;
	fdf->end_x = fdf->margins_info.x_margin + ((cos(fdf->projection_info.roll)
				* (x_index + 1 - (fdf->data_mesh->mesh_width - 1) / 2))
			- (sin(fdf->projection_info.roll) * (y_index
					- (fdf->data_mesh->mesh_height - 1) / 2)))
		* fdf->scaling_factor;
	fdf->end_y = fdf->margins_info.y_margin - (((-sin(fdf->projection_info.roll)
					* sin(fdf->projection_info.yaw)
					* (x_index + 1 - (fdf->data_mesh->mesh_width - 1)
						/ 2)) - (cos(fdf->projection_info.roll)
					* sin(fdf->projection_info.yaw) * (y_index
						- (fdf->data_mesh->mesh_height - 1) / 2))
				+ (cos(fdf->projection_info.yaw)
					* (z * fdf->additional_altitude - (fdf->data_mesh->altitude
							+ 1) / 2))) * fdf->scaling_factor);
	draw_line_image(fdf, data);
}

void	draw_lines_axonometric(int x_index, int y_index,
							t_graphics_scene *fdf, int *data)
{
	double	x;
	double	y;
	double	z;

	x = x_index;
	y = y_index;
	z = fdf->data_mesh->mesh[y_index][x_index];
	fdf->start_z = z;
	fdf->start_x = fdf->margins_info.x_margin + ((cos(fdf->projection_info.roll)
				* (x - (fdf->data_mesh->mesh_width - 1) / 2)) - (sin
				(fdf->projection_info.roll) * (y - (fdf->data_mesh->mesh_height
						- 1) / 2))) * fdf->scaling_factor;
	fdf->start_y = fdf->margins_info.y_margin
		- (((-sin(fdf->projection_info.roll) * sin(fdf->projection_info.yaw)
					* (x - (fdf->data_mesh->mesh_width - 1) / 2))
				- (cos(fdf->projection_info.roll) * sin
					(fdf->projection_info.yaw) * (y
						- (fdf->data_mesh->mesh_height - 1) / 2))
				+ (cos(fdf->projection_info.yaw) * (z * fdf->additional_altitude
						- (fdf->data_mesh->altitude + 1) / 2)))
			* fdf->scaling_factor);
	if (y_index < fdf->data_mesh->mesh_height - 1)
		draw_vertical_line(x_index, y_index, fdf, data);
	if (x_index < fdf->data_mesh->mesh_width - 1)
		draw_horizontal_line(x_index, y_index, fdf, data);
}
