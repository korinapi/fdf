/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpuiu <cpuiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:08:02 by cpuiu             #+#    #+#             */
/*   Updated: 2024/01/24 13:18:01 by cpuiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	str_interface(t_graphics_scene *fdf)
{
	if (fdf->projection_type == PROJ_AXO)
		mlx_string_put(fdf->mlx, fdf->window, 45, 100,
			0x00015f2c, "axonometric");
	else
		mlx_string_put(fdf->mlx, fdf->window, 45, 100,
			0x00e1cfc9, "axonometric");
	if (fdf->projection_type == PROJ_OBLIQUE)
		mlx_string_put(fdf->mlx, fdf->window, 65, 175, 0x00015f2c, "oblique");
	else
		mlx_string_put(fdf->mlx, fdf->window, 65, 175, 0x00e1cfc9, "oblique");
}
