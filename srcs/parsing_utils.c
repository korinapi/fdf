/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpuiu <cpuiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:57:17 by cpuiu             #+#    #+#             */
/*   Updated: 2024/01/26 10:56:24 by cpuiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	nb_words(char *line)
{
	int	i;
	int	parseword;
	int	nb_words;

	i = 0;
	parseword = 0;
	nb_words = 0;
	while (line[i])
	{
		if (line[i] != ' ' && !parseword)
		{
			parseword = 1;
			nb_words++;
		}
		if (line[i] == ' ' && parseword)
		{
			parseword = 0;
		}
		i++;
	}
	return (nb_words);
}

int	*ft_sub_tab(t_mesh *mesh, char **split)
{
	int	*result;
	int	i;
	int	value;

	i = 0;
	result = (int *)malloc(sizeof(int) * mesh->mesh_width);
	if (!(result))
		return (NULL);
	while (split[i])
	{
		value = ft_atoi(split[i]) + 1;
		if (value > mesh->max_point)
			mesh->max_point = value;
		if (value < mesh->min_point)
			mesh->min_point = value;
		result[i] = value;
		i++;
	}
	return (result);
}

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		ft_strdel(&(split[i]));
		i++;
	}
	free(split);
}
