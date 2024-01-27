/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpuiu <cpuiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:10:41 by cpuiu             #+#    #+#             */
/*   Updated: 2024/01/24 15:17:17 by cpuiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	color(int red, int green, int blue)
{
	return ((red << 16) | (green << 8) | blue);
}

int	gradient_color(double gradient_factor, int top_color, int bottom_color)
{
	int	red;
	int	green;
	int	blue;

	red = (int)((1 - gradient_factor) * ((top_color >> 16) & 0xFF)
			+ gradient_factor * ((bottom_color >> 16) & 0xFF));
	green = (int)((1 - gradient_factor) * ((top_color >> 8) & 0xFF)
			+ gradient_factor * ((bottom_color >> 8) & 0xFF));
	blue = (int)((1 - gradient_factor) * (top_color & 0xFF)
			+ gradient_factor * (bottom_color & 0xFF));
	return (color(red, green, blue));
}

int	interpolate_color(double current_height, int average, t_graphics_scene *fdf)
{
	double	gradient_factor;
	int		red;
	int		green;
	int		blue;

	gradient_factor = current_height / average;
	red = (int)((1 - gradient_factor) * fdf->top_color[0]
			+ gradient_factor * fdf->bottom_color[0]);
	green = (int)((1 - gradient_factor) * fdf->top_color[1]
			+ gradient_factor * fdf->bottom_color[1]);
	blue = (int)((1 - gradient_factor) * fdf->top_color[2]
			+ gradient_factor * fdf->bottom_color[2]);
	return (color(red, green, blue));
}
