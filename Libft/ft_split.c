/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpuiu <cpuiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 20:59:41 by cpuiu             #+#    #+#             */
/*   Updated: 2023/10/07 18:37:25 by cpuiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_str(char const *s, char c)
{
	int	sum;

	sum = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			sum++;
		while (*s && *s != c)
			s++;
	}
	return (sum);
}

void	ft_free_array(char **new_array)
{
	int	i;

	i = 0;
	while (new_array[i])
	{
		free(new_array[i]);
		i++;
	}
	free (new_array);
}

void	ft_allocate(char **array, char const *s, char c)
{
	char		**new_array;
	char const	*temp;

	new_array = array;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		temp = s;
		while (*temp && *temp != c)
			temp++;
		if (temp > s)
		{
			*new_array = ft_substr(s, 0, temp - s);
			if (!*new_array)
			{
				ft_free_array(new_array);
				return ;
			}
			new_array++;
		}
		s = temp;
	}
	*new_array = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**array;

	if (!s)
		return (NULL);
	array = (char **)malloc(sizeof(char *) * (ft_count_str(s, c) + 1));
	if (!array)
		return (NULL);
	ft_allocate(array, s, c);
	return (array);
}
