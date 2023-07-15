/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 13:13:14 by niromano          #+#    #+#             */
/*   Updated: 2023/07/15 03:33:30 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_escape(char **map)
{
	int	i;
	int	j;
	int	count_e;

	i = 0;
	j = 0;
	count_e = 0;
	while (map[i] != NULL)
	{
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'E')
				count_e += 1;
			j ++;
		}
		j = 0;
		i ++;
	}
	if (count_e < 1)
		error_map(map, 6);
	else if (count_e > 1)
		error_map(map, 7);
}

void	check_player(char **map)
{
	int	i;
	int	j;
	int	count_p;

	i = 0;
	j = 0;
	count_p = 0;
	while (map[i] != NULL)
	{
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'P')
				count_p += 1;
			j ++;
		}
		j = 0;
		i ++;
	}
	if (count_p < 1)
		error_map(map, 8);
	else if (count_p > 1)
		error_map(map, 9);
}

void	check_collectibles(char **map)
{
	int	i;
	int	j;
	int	count_c;

	i = 0;
	j = 0;
	count_c = 0;
	while (map[i] != NULL)
	{
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'C')
				count_c += 1;
			j ++;
		}
		j = 0;
		i ++;
	}
	if (count_c < 1)
		error_map(map, 10);
}
