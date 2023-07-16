/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 07:32:19 by niromano          #+#    #+#             */
/*   Updated: 2023/07/16 12:52:06 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	search_player(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (mlx->map[i] != NULL)
	{
		while (mlx->map[i][j] != '\0')
		{
			if (mlx->map[i][j] == 'P')
			{
				mlx->p_x = j;
				mlx->p_y = i;
			}
			j ++;
		}
		j = 1;
		i ++;
	}
}

void	count_collectibles(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	mlx->collec = 0;
	while (mlx->map[i] != NULL)
	{
		while (mlx->map[i][j] != '\0')
		{
			if (mlx->map[i][j] == 'C')
				mlx->collec += 1;
			j ++;
		}
		j = 1;
		i ++;
	}
}

void	search_escape(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (mlx->map[i] != NULL)
	{
		while (mlx->map[i][j] != '\0')
		{
			if (mlx->map[i][j] == 'E')
			{
				mlx->spike_x = j;
				mlx->spike_y = i;
			}
			j ++;
		}
		j = 1;
		i ++;
	}
}

void	set_data(t_mlx *mlx)
{
	search_player(mlx);
	count_collectibles(mlx);
	search_escape(mlx);
	mlx->nb_move = 0;
	mlx->timer = 0;
}
