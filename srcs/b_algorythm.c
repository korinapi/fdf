/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_algorythm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpuiu <cpuiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:50:11 by cpuiu             #+#    #+#             */
/*   Updated: 2024/01/24 20:18:54 by cpuiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_data_x(int x, int y, t_graphics_scene *fdf, int *data)
{
	int	index;

	index = x + WINDOW_WIDTH * y;
	if (index > 0 && index < (WINDOW_WIDTH * WINDOW_HEIGHT)
		&& x < WINDOW_WIDTH && y < WINDOW_HEIGHT && x > 0 && y > 0)
		data[x + y * WINDOW_WIDTH] = standard_color_x(x, fdf);
}

void	print_data_y(int x, int y, t_graphics_scene *fdf, int *data)
{
	int	index;

	index = x + WINDOW_WIDTH * y;
	if (index > 0 && index < (WINDOW_WIDTH * WINDOW_HEIGHT)
		&& x < WINDOW_WIDTH && y < WINDOW_HEIGHT && x > 0 && y > 0)
		data[x + y * WINDOW_WIDTH] = standard_color_y(y, fdf);
}

void	b_top(int x, int y, t_graphics_scene *fdf, int *data)
{
	int	i;

	i = 0;
	print_data_x(x, y, fdf, data);
	fdf->drawing_info.error = 2 * fdf->drawing_info.delta_y
		- fdf->drawing_info.delta_x;
	fdf->drawing_info.increment_1 = 2
		* (fdf->drawing_info.delta_y - fdf->drawing_info.delta_x);
	fdf->drawing_info.increment_2 = 2 * fdf->drawing_info.delta_y;
	while (i < fdf->drawing_info.delta_x)
	{
		if (fdf->drawing_info.error >= 0)
		{
			y += fdf->drawing_info.increment_y;
			fdf->drawing_info.error += fdf->drawing_info.increment_1;
		}
		else
			fdf->drawing_info.error += fdf->drawing_info.increment_2;
		x += fdf->drawing_info.increment_x;
		print_data_x(x, y, fdf, data);
		i++;
	}
}

void	b_bottom(int x, int y, t_graphics_scene *fdf, int *data)
{
	int	i;

	i = 0;
	print_data_y(x, y, fdf, data);
	fdf->drawing_info.error = 2 * fdf->drawing_info.delta_x
		- fdf->drawing_info.delta_y;
	fdf->drawing_info.increment_1 = 2
		* (fdf->drawing_info.delta_x - fdf->drawing_info.delta_y);
	fdf->drawing_info.increment_2 = 2 * fdf->drawing_info.delta_x;
	while (i < fdf->drawing_info.delta_y)
	{
		if (fdf->drawing_info.error >= 0)
		{
			x += fdf->drawing_info.increment_x;
			fdf->drawing_info.error += fdf->drawing_info.increment_1;
		}
		else
			fdf->drawing_info.error += fdf->drawing_info.increment_2;
		y += fdf->drawing_info.increment_y;
		print_data_y(x, y, fdf, data);
		i++;
	}
}

int	draw_line_tierce(t_graphics_scene *fdf, int *data)
{
	int	x;
	int	y;

	fdf->drawing_info.delta_x = fdf->end_x - fdf->start_x;
	fdf->drawing_info.delta_y = fdf->end_y - fdf->start_y;
	if (fdf->drawing_info.delta_x < 0)
		fdf->drawing_info.delta_x = -fdf->drawing_info.delta_x;
	if (fdf->drawing_info.delta_y < 0)
		fdf->drawing_info.delta_y = -fdf->drawing_info.delta_y;
	fdf->drawing_info.increment_x = 1;
	if (fdf->end_x < fdf->start_x)
		fdf->drawing_info.increment_x = -1;
	fdf->drawing_info.increment_y = 1;
	if (fdf->end_y < fdf->start_y)
		fdf->drawing_info.increment_y = -1;
	x = fdf->start_x;
	y = fdf->start_y;
	if (fdf->drawing_info.delta_x > fdf->drawing_info.delta_y)
		b_top(x, y, fdf, data);
	else
		b_bottom(x, y, fdf, data);
	return (0);
}
