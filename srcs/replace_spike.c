/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_spike.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:00:24 by niromano          #+#    #+#             */
/*   Updated: 2023/07/13 18:00:52 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	spike_open(t_mlx *mlx)
{
	int	x;
	int	y;

	x = (mlx->spike_x * 60);
	y = (mlx->spike_y * 60);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img_e_o, x, y);
}

void	spike_close(t_mlx *mlx, int p_x, int p_y)
{
	int	x;
	int	y;

	x = (mlx->spike_x * 60);
	y = (mlx->spike_y * 60);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img_e, x, y);
	mlx->map[p_y][p_x] = 'E';
}
