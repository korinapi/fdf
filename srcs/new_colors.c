/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpuiu <cpuiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:21:26 by cpuiu             #+#    #+#             */
/*   Updated: 2024/01/26 10:53:20 by cpuiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	iterate_color(t_graphics_scene *fdf, int *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < fdf->data_mesh->mesh_height)
	{
		j = 0;
		while (j < fdf->data_mesh->mesh_width)
		{
			if (fdf->projection_type == PROJ_AXO)
				draw_lines_axonometric(j, i, fdf, data);
			if (fdf->projection_type == PROJ_OBLIQUE)
				lines_obliq_image(j, i, fdf, data);
			j++;
		}
		i++;
	}
}

void	action_color_image(t_graphics_scene *fdf)
{
	int		*data;

	if (fdf->figure_image == NULL)
	{
		ft_putendl_fd("mlx malloc error.", 2);
		exit(1);
	}
	data = (int *)mlx_get_data_addr(fdf->figure_image,
			&(fdf->image_info.bytes_per_pixel),
			&(fdf->image_info.line_size), &(fdf->image_info.bytes_order));
	fdf->image_info.image_width = WINDOW_WIDTH;
	fdf->image_info.image_height = WINDOW_HEIGHT;
	iterate_color(fdf, data);
	mlx_put_image_to_window(fdf->mlx, fdf->window, fdf->figure_image, 0, 0);
	mlx_destroy_image(fdf->mlx, fdf->figure_image);
}

void	color_fig_image(t_graphics_scene *fdf)
{
	fdf->figure_image = mlx_new_image(fdf->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	action_color_image(fdf);
	str_interface(fdf);
}
