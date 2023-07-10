/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_possible_to_end.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 13:39:01 by niromano          #+#    #+#             */
/*   Updated: 2023/07/10 15:06:52 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	error_malloc_matrix(char **temp, char **map)
{
	if (temp != NULL)
		free_mat(temp);
	free_mat(map);
	ft_putstr_fd("Malloc failed !\n", 2);
	exit(EXIT_FAILURE);
}

char	**create_temp_map(char **map)
{
	char	**temp;
	int		i;

	i = 0;
	while (map[i] != NULL)
		i ++;
	temp = malloc(sizeof(char *) * (i + 1));
	if (temp == NULL)
		error_malloc_matrix(temp, map);
	i = 0;
	while (map[i] != NULL)
	{
		temp[i] = ft_strdup(map[i]);
		if (temp[i] == NULL)
			error_malloc_matrix(temp, map);
		i ++;
	}
	temp[i] = NULL;
	return (temp);
}

void	check_end(char **temp, char **map)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	while (temp[i] != NULL)
	{
		while (temp[i][j] != '\0')
		{
			if (temp[i][j] == 'C' || temp[i][j] == 'E')
			{
				free_mat(temp);
				error_map(map, 9);
			}
			j ++;
		}
		j = 0;
		i ++;
	}
}

void	fill_temp_map(char **temp)
{
	if (temp) {}
}

void	check_if_possible_to_end(char **map)
{
	char	**temp;

	temp = create_temp_map(map);
	fill_temp_map(temp);
	check_end(temp, map);
	free_mat(temp);
}
