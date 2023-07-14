/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   border_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 01:20:39 by niromano          #+#    #+#             */
/*   Updated: 2023/07/15 01:21:00 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	border_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[0][j] != '\n')
		map[0][j++] = '2';
	while (map[i + 1] != NULL)
	{
		map[i][0] = '2';
		map[i][ft_strlen(map[i]) - 2] = '2';
		i ++;
	}
	j = 0;
	while (map[i][j] != '\0')
		map[i][j++] = '2';
}
