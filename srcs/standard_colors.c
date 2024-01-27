/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   standard_colors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpuiu <cpuiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 20:51:44 by cpuiu             #+#    #+#             */
/*   Updated: 2024/01/24 15:19:52 by cpuiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	standard_color_x(int x, t_graphics_scene *fdf)
{
	double	current_height;
	int		average;
	int		top_color;
	int		bottom_color;

	current_height = fdf->start_z + (1 - (double)abs(x - fdf->end_x)
			/ abs(fdf->end_x - fdf->start_x)) * (fdf->end_z - fdf->start_z);
	average = fdf->data_mesh->max_point
		+ fdf->data_mesh->min_point;
	top_color = fdf->top_color[0];
	bottom_color = fdf->bottom_color[0];
	if (current_height <= average)
		return (interpolate_color(current_height, average, fdf));
	else
		return (gradient_color((current_height - average)
				/ (fdf->data_mesh->max_point - average),
				bottom_color, top_color));
}

int	standard_color_y(int y, t_graphics_scene *fdf)
{
	double	current_height;
	int		average;
	int		top_color;
	int		bottom_color;

	current_height = fdf->start_z + (1 - (double)abs(y - fdf->end_y)
			/ abs(fdf->end_y - fdf->start_y)) * (fdf->end_z - fdf->start_z);
	average = fdf->data_mesh->max_point + fdf->data_mesh->min_point;
	top_color = fdf->top_color[0];
	bottom_color = fdf->bottom_color[0];
	if (current_height <= average)
		return (interpolate_color(current_height, average, fdf));
	else
		return (gradient_color((current_height - average)
				/ (fdf->data_mesh->max_point - average),
				bottom_color, top_color));
}
