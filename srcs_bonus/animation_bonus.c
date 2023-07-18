/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 01:17:20 by niromano          #+#    #+#             */
/*   Updated: 2023/07/18 10:59:58 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	animation(t_mlx *mlx)
{
	int	px;
	int	py;
	int	sx;
	int	sy;

	px = mlx->p_x * 60;
	py = mlx->p_y * 60;
	sx = mlx->spike_x * 60;
	sy = mlx->spike_y * 60;
	if (mlx->timer == 0 && mlx->map[mlx->p_y][mlx->p_x] == 'P')
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.p_1, px, py);
	else if ((mlx->timer == 25000 || mlx->timer == 75000)
		&& mlx->map[mlx->p_y][mlx->p_x] == 'P')
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.p_2, px, py);
	else if (mlx->timer == 50000 && mlx->map[mlx->p_y][mlx->p_x] == 'P')
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.p_3, px, py);
	if (!(px == sx && py == sy) && mlx->timer == 0 && mlx->collec != 0)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.e_o, sx, sy);
	else if (!(px == sx && py == sy) && mlx->timer == 55000 && mlx->collec != 0)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.e_c, sx, sy);
	if (mlx->timer++ > 100000)
		mlx->timer = 0;
	return (0);
}
