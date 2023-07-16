/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 01:23:02 by niromano          #+#    #+#             */
/*   Updated: 2023/07/16 12:50:36 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	init_map(t_mlx *mlx)
{
	int	x;
	int	y;

	x = ft_strlen(mlx->map[0]) - 1;
	y = 0;
	while (mlx->map[y] != NULL)
		y ++;
	mlx->len_w_x = x * 60;
	mlx->len_w_y = y * 60;
	if (mlx->len_w_x > 1920 || mlx->len_w_y > 1020)
		error_len_of_map(mlx);
}
