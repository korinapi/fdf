/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   axonometric_min_params.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpuiu <cpuiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:28:38 by cpuiu             #+#    #+#             */
/*   Updated: 2024/01/24 18:26:23 by cpuiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	calculate_x_projection(t_graphics_scene *fdf, int i, int j);
double	calculate_y_projection(t_graphics_scene *fdf, int i, int j);

double	calculate_min_projection(t_graphics_scene *fdf, int is_x)
{
	int		i;
	int		j;
	double	min;
	double	projection;

	min = MAXDOUBLE;
	i = 0;
	while (i < fdf->data_mesh->mesh_height)
	{
		j = 0;
		while (j < fdf->data_mesh->mesh_width)
		{
			if (is_x)
				projection = calculate_x_projection(fdf, i, j);
			else
				projection = calculate_y_projection(fdf, i, j);
			if (min > projection)
				min = projection;
			j++;
		}
		i++;
	}
	return (min);
}

double	calculate_x_projection(t_graphics_scene *fdf, int i, int j)
{
	return ((cos(fdf->projection_info.pitch)
			* (j - (fdf->data_mesh->mesh_width - 1) / 2))
		- (sin(fdf->projection_info.pitch)
			* (i - (fdf->data_mesh->mesh_height - 1) / 2)));
}

double	calculate_y_projection(t_graphics_scene *fdf, int i, int j)
{
	return (-((-sin(fdf->projection_info.pitch)
				* sin(fdf->projection_info.yaw)
				* (j - (fdf->data_mesh->mesh_width - 1) / 2))
			- (cos(fdf->projection_info.pitch)
				* sin(fdf->projection_info.yaw)
				* (i - (fdf->data_mesh->mesh_height - 1) / 2))
			+ (cos(fdf->projection_info.yaw)
				* (fdf->data_mesh->mesh[i][j]
				* fdf->additional_altitude
				- (fdf->data_mesh->altitude + 1) / 2))));
}

double	min_x_axonometric(t_graphics_scene *fdf)
{
	return (calculate_min_projection(fdf, 1));
}

double	min_y_axonometric(t_graphics_scene *fdf)
{
	return (calculate_min_projection(fdf, 0));
}
