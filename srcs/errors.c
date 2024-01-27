/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpuiu <cpuiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:40:26 by cpuiu             #+#    #+#             */
/*   Updated: 2024/01/27 10:44:30 by cpuiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	errors(int argc, char **argv, t_mesh **mesh)
{
	int	err;

	err = 0;
	if (argc != 2)
	{
		ft_putendl_fd("One argument only", 2);
		return (0);
	}
	*mesh = new_mesh(argv[1], &err);
	if (*mesh == NULL)
	{
		ft_putendl_fd("ERROR", 2);
		return (0);
	}
	return (1);
}
