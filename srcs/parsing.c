/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpuiu <cpuiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:28:37 by cpuiu             #+#    #+#             */
/*   Updated: 2024/01/26 12:14:19 by cpuiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	process_check_mesh(int nb_lines, char *line, t_mesh *result);
int		check_mesh(char *mesh_name, t_mesh *result, char *line);
int		process_new_mesh(char *mesh_name, t_mesh *result);
int		checker(char *mesh_name, t_mesh *result);

t_mesh	*new_mesh(char *mesh_name, int *error)
{
	char	*line;
	t_mesh	*result;

	line = NULL;
	result = (t_mesh *)malloc(sizeof(t_mesh));
	result->max_point = 0;
	result->min_point = 0;
	result->mesh_width = -1;
	*error = check_mesh(mesh_name, result, line);
	if ((*error) != 0)
		return (NULL);
	result->mesh = (int **)malloc(sizeof(int *) * result->mesh_height);
	if (!result->mesh)
		return (NULL);
	if (process_new_mesh(mesh_name, result))
		return (NULL);
	return (result);
}

int	checker(char *mesh_name, t_mesh *result)
{
	int		fd;
	int		ret;
	char	*line;
	char	**split;
	int		i;

	i = 0;
	fd = open(mesh_name, O_RDONLY);
	if (fd == -1)
		return (-1);
	while (1)
	{
		ret = get_next_line(fd, &line);
		if (ret <= 0)
			break ;
		split = ft_split(line, ' ');
		if (!split)
			return (1);
		result->mesh[i] = ft_sub_tab(result, split);
		if (!(result->mesh[i]))
			return (1);
		ft_free_split(split);
		ft_strdel(&line);
		i++;
	}
	return (0);
}

int	process_new_mesh(char *mesh_name, t_mesh *result)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(mesh_name, O_RDONLY);
	checker(mesh_name, result);
	ft_strdel(&line);
	close (fd);
	result->altitude = result->max_point - result->min_point;
	return (0);
}

int	check_mesh(char *mesh_name, t_mesh *result, char *line)
{
	int	fd;
	int	nb_lines;
	int	ret;

	nb_lines = 0;
	fd = open(mesh_name, O_RDONLY);
	if (fd == -1)
		return (-1);
	while (1)
	{
		ret = get_next_line(fd, &line);
		if (!ret)
			break ;
		process_check_mesh(nb_lines, line, result);
		nb_lines++;
		ft_strdel(&line);
	}
	ft_strdel(&line);
	close(fd);
	if (result->mesh_width < 0)
		return (2);
	else
		result->mesh_height = nb_lines;
	return (0);
}

void	process_check_mesh(int nb_lines, char *line, t_mesh *result)
{
	if (nb_lines == 0)
		result->mesh_width = nb_words(line);
	if (nb_lines != 0 && nb_words(line) != result->mesh_width)
		result->mesh_width = -1;
}
