/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   axonometric_max_params.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpuiu <cpuiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:22:28 by cpuiu             #+#    #+#             */
/*   Updated: 2024/01/24 18:25:59 by cpuiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	calculate_max_x_projection(t_graphics_scene *fdf, int i, int j);
double	calculate_max_y_projection(t_graphics_scene *fdf, int i, int j);

double	calculate_max_projection(t_graphics_scene *fdf, int is_x)
{
	int		i;
	int		j;
	double	max;
	double	projection;

	max = MINDOUBLE;
	i = 0;
	while (i < fdf->data_mesh->mesh_height)
	{
		j = 0;
		while (j < fdf->data_mesh->mesh_width)
		{
			if (is_x)
				projection = calculate_max_x_projection(fdf, i, j);
			else
				projection = calculate_max_y_projection(fdf, i, j);
			if (max < projection)
				max = projection;
			j++;
		}
		i++;
	}
	return (max);
}

double	calculate_max_x_projection(t_graphics_scene *fdf, int i, int j)
{
	return ((cos(fdf->projection_info.roll)
			* (j - (fdf->data_mesh->mesh_width - 1) / 2))
		- (sin(fdf->projection_info.roll)
			* (i - (fdf->data_mesh->mesh_height - 1) / 2)));
}

double	calculate_max_y_projection(t_graphics_scene *fdf, int i, int j)
{
	return (-((-sin(fdf->projection_info.roll)
				* sin(fdf->projection_info.yaw)
				* (j - (fdf->data_mesh->mesh_width - 1) / 2))
			- (cos(fdf->projection_info.roll)
				* sin(fdf->projection_info.yaw)
				* (i - (fdf->data_mesh->mesh_height - 1) / 2))
			+ (cos(fdf->projection_info.yaw)
				* (fdf->data_mesh->mesh[i][j]
				* fdf->additional_altitude
				- (fdf->data_mesh->altitude + 1) / 2))));
}

double	max_x_axonometric(t_graphics_scene *fdf)
{
	return (calculate_max_projection(fdf, 1));
}

double	max_y_axonometric(t_graphics_scene *fdf)
{
	return (calculate_max_projection(fdf, 0));
}
