/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obliq_parameters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpuiu <cpuiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:06:07 by cpuiu             #+#    #+#             */
/*   Updated: 2024/01/24 18:57:51 by cpuiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	min_x_obliq(t_graphics_scene *fdf)
{
	int	i;
	int	j;
	int	min;
	int	x_projection;

	min = MAXDOUBLE;
	i = 0;
	while (i < fdf->data_mesh->mesh_height)
	{
		j = 0;
		while (j < fdf->data_mesh->mesh_width)
		{
			x_projection = ((j + (((double)1 / (double)2)
							* (double)(fdf->data_mesh->mesh[i][j]
								* fdf->additional_altitude))
						* cos(fdf->projection_info.obliq)));
			if (min > x_projection)
				min = x_projection;
			j++;
		}
		i++;
	}
	return (min);
}

int	max_x_obliq(t_graphics_scene *fdf)
{
	int	i;
	int	j;
	int	max;
	int	x_projection;

	max = MINDOUBLE;
	i = 0;
	while (i < fdf->data_mesh->mesh_height)
	{
		j = 0;
		while (j < fdf->data_mesh->mesh_width)
		{
			x_projection = ((j + (((double)1 / (double)2)
							* (double)fdf->data_mesh->mesh[i][j]
							* fdf->additional_altitude)
						* cos(fdf->projection_info.obliq)));
			if (max < x_projection)
				max = x_projection;
			j++;
		}
		i++;
	}
	return (max);
}

int	min_y_obliq(t_graphics_scene *fdf)
{
	int	i;
	int	j;
	int	min;
	int	proj_y;

	min = MAXDOUBLE;
	i = 0;
	while (i < fdf->data_mesh->mesh_height)
	{
		j = 0;
		while (j < fdf->data_mesh->mesh_width)
		{
			proj_y = ((i + (((double)1 / (double)2)
							* (double)fdf->data_mesh->mesh[i][j]
							* fdf->additional_altitude)
						* sin(fdf->projection_info.obliq)));
			if (min > proj_y)
				min = proj_y;
			j++;
		}
		i++;
	}
	return (min);
}

int	max_y_obliq(t_graphics_scene *fdf)
{
	int	i;
	int	j;
	int	max;
	int	proj_y;

	max = MINDOUBLE;
	i = 0;
	while (i < fdf->data_mesh->mesh_height)
	{
		j = 0;
		while (j < fdf->data_mesh->mesh_width)
		{
			proj_y = ((i + (((double)1 / (double)2)
							* (double)fdf->data_mesh->mesh[i][j]
							* fdf->additional_altitude)
						* sin(fdf->projection_info.obliq)));
			if (max < proj_y)
				max = proj_y;
			j++;
		}
		i++;
	}
	return (max);
}
