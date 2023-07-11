/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 08:43:12 by niromano          #+#    #+#             */
/*   Updated: 2023/07/11 09:42:33 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	try_escape(t_mlx *mlx)
{
	if (mlx->collectibles == 0)
		clear_all(mlx);
}

void	move_w(t_mlx *mlx)
{
	if (mlx->map[mlx->p_y - 1][mlx->p_x] == '0' || mlx->map[mlx->p_y - 1][mlx->p_x] == 'C' || mlx->map[mlx->p_y - 1][mlx->p_x] == 'E')
	{
		if (mlx->p_y == mlx->spike_y && mlx->p_x == mlx->spike_x)
			
		if (mlx->map[mlx->p_y - 1][mlx->p_x] == 'E')
			try_escape(mlx);
		if (mlx->map[mlx->p_y - 1][mlx->p_x] == 'C')
			mlx->collectibles --;
		mlx->map[mlx->p_y][mlx->p_x] = '0';
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img_0, mlx->p_x * 60, mlx->p_y * 60);
		mlx->p_y --;
		mlx->map[mlx->p_y][mlx->p_x] = 'P';
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img_p, mlx->p_x * 60, mlx->p_y * 60);
	}
}

void	move_a(t_mlx *mlx)
{
	if (mlx->map[mlx->p_y][mlx->p_x - 1] == '0' || mlx->map[mlx->p_y][mlx->p_x - 1] == 'C' || mlx->map[mlx->p_y][mlx->p_x - 1] == 'E')
	{
		if (mlx->map[mlx->p_y][mlx->p_x - 1] == 'E')
			try_escape(mlx);
		if (mlx->map[mlx->p_y][mlx->p_x - 1] == 'C')
			mlx->collectibles --;
		mlx->map[mlx->p_y][mlx->p_x] = '0';
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img_0, mlx->p_x * 60, mlx->p_y * 60);
		mlx->p_x --;
		mlx->map[mlx->p_y][mlx->p_x] = 'P';
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img_p, mlx->p_x * 60, mlx->p_y * 60);
	}
}

void	move_s(t_mlx *mlx)
{
	if (mlx->map[mlx->p_y + 1][mlx->p_x] == '0' || mlx->map[mlx->p_y + 1][mlx->p_x] == 'C' || mlx->map[mlx->p_y + 1][mlx->p_x] == 'E')
	{
		if (mlx->map[mlx->p_y + 1][mlx->p_x] == 'E')
			try_escape(mlx);
		if (mlx->map[mlx->p_y + 1][mlx->p_x] == 'C')
			mlx->collectibles --;
		mlx->map[mlx->p_y][mlx->p_x] = '0';
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img_0, mlx->p_x * 60, mlx->p_y * 60);
		mlx->p_y ++;
		mlx->map[mlx->p_y][mlx->p_x] = 'P';
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img_p, mlx->p_x * 60, mlx->p_y * 60);
	}
}

void	move_d(t_mlx *mlx)
{
	if (mlx->map[mlx->p_y][mlx->p_x + 1] == '0' || mlx->map[mlx->p_y][mlx->p_x + 1] == 'C' || mlx->map[mlx->p_y][mlx->p_x + 1] == 'E')
	{
		if (mlx->map[mlx->p_y][mlx->p_x + 1] == 'E')
			try_escape(mlx);
		if (mlx->map[mlx->p_y][mlx->p_x + 1] == 'C')
			mlx->collectibles --;
		mlx->map[mlx->p_y][mlx->p_x] = '0';
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img_0, mlx->p_x * 60, mlx->p_y * 60);
		mlx->p_x ++;
		mlx->map[mlx->p_y][mlx->p_x] = 'P';
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img_p, mlx->p_x * 60, mlx->p_y * 60);
	}
}
