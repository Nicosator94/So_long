/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 19:16:43 by niromano          #+#    #+#             */
/*   Updated: 2023/07/16 12:51:28 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	check_rectangle(char **map)
{
	int	i;
	int	len;

	i = 1;
	len = ft_strlen(map[0]);
	while (map[i] != NULL)
	{
		if (map[i + 1] == NULL)
			len -= 1;
		if (len != (int)ft_strlen(map[i]))
		{
			ft_putstr_fd("Error\n", 2);
			ft_putstr_fd("The map isn't a rectangle !\n", 2);
			free_mat(map);
			exit(EXIT_FAILURE);
		}
		i ++;
	}
}

void	error_map(char **map, int trigger)
{
	ft_putstr_fd("Error\n", 2);
	if (trigger == 1)
		ft_putstr_fd("The map is not closed at the top !\n", 2);
	else if (trigger == 2)
		ft_putstr_fd("The map is not closed on the left !\n", 2);
	else if (trigger == 3)
		ft_putstr_fd("The map is not closed on the right !\n", 2);
	else if (trigger == 4)
		ft_putstr_fd("The map is not closed at the bottom !\n", 2);
	else if (trigger == 5)
		ft_putstr_fd("The map contains invalid characters !\n", 2);
	else if (trigger == 6)
		ft_putstr_fd("The map does not contain any escape !\n", 2);
	else if (trigger == 7)
		ft_putstr_fd("The map contains too much escapes !\n", 2);
	else if (trigger == 8)
		ft_putstr_fd("The map does not contain any spawn !\n", 2);
	else if (trigger == 9)
		ft_putstr_fd("The map contains too much spawns !\n", 2);
	else if (trigger == 10)
		ft_putstr_fd("The map does not contain any collectibles !\n", 2);
	else if (trigger == 11)
		ft_putstr_fd("The map can't be finished !\n", 2);
	free_mat(map);
	exit(EXIT_FAILURE);
}

void	check_close(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[0][j] != '\n')
	{
		if (map[0][j++] != '1')
			error_map(map, 1);
	}
	while (map[i + 1] != NULL)
	{
		if (map[i][0] != '1')
			error_map(map, 2);
		if (map[i][ft_strlen(map[i]) - 2] != '1')
			error_map(map, 3);
		i ++;
	}
	j = 0;
	while (map[i][j] != '\0')
	{
		if (map[i][j++] != '1')
			error_map(map, 4);
	}
}

void	check_invalid_character(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i] != NULL)
	{
		while (map[i][j] != '\0')
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'P'
				&& map[i][j] != 'C' && map[i][j] != 'E' && map[i][j] != '\n')
				error_map(map, 5);
			j ++;
		}
		j = 0;
		i ++;
	}
}

void	parsing_map(char **map)
{
	check_rectangle(map);
	check_close(map);
	check_invalid_character(map);
	check_escape(map);
	check_player(map);
	check_collectibles(map);
	check_if_possible_to_end(map);
}
