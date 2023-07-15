/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 08:43:12 by niromano          #+#    #+#             */
/*   Updated: 2023/07/15 22:02:10 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	try_escape(t_mlx *mlx)
{
	if (mlx->collec == 0)
	{
		mlx->nb_move += 1;
		ft_printf("Congrats, you win with only %d steps !\n", mlx->nb_move);
		clear_all_success(mlx);
	}
}

void	move_w(t_mlx *mlx)
{
	if (mlx->map[mlx->p_y - 1][mlx->p_x] == '0' ||
		mlx->map[mlx->p_y - 1][mlx->p_x] == 'C' ||
		mlx->map[mlx->p_y - 1][mlx->p_x] == 'E')
	{
		if (mlx->map[mlx->p_y - 1][mlx->p_x] == 'E')
			try_escape(mlx);
		if (mlx->map[mlx->p_y - 1][mlx->p_x] == 'C')
		{
			mlx->collec --;
			if (mlx->collec == 0)
				spike_open(mlx);
		}
		mlx->map[mlx->p_y][mlx->p_x] = '0';
		mlx_put_image_to_window(mlx->mlx, mlx->win,
			mlx->img.gro, mlx->p_x * 60, mlx->p_y * 60);
		mlx->p_y --;
		mlx->map[mlx->p_y][mlx->p_x] = 'P';
		mlx_put_image_to_window(mlx->mlx, mlx->win,
			mlx->img.p_1, mlx->p_x * 60, mlx->p_y * 60);
		mlx->nb_move += 1;
		print_counter(mlx);
		if (mlx->p_y + 1  == mlx->spike_y && mlx->p_x == mlx->spike_x)
			spike_close(mlx, mlx->p_x, mlx->p_y + 1);
	}
}

void	move_a(t_mlx *mlx)
{
	if (mlx->map[mlx->p_y][mlx->p_x - 1] == '0' ||
		mlx->map[mlx->p_y][mlx->p_x - 1] == 'C' ||
		mlx->map[mlx->p_y][mlx->p_x - 1] == 'E')
	{
		if (mlx->map[mlx->p_y][mlx->p_x - 1] == 'E')
			try_escape(mlx);
		if (mlx->map[mlx->p_y][mlx->p_x - 1] == 'C')
		{
			mlx->collec --;
			if (mlx->collec == 0)
				spike_open(mlx);
		}
		mlx->map[mlx->p_y][mlx->p_x] = '0';
		mlx_put_image_to_window(mlx->mlx, mlx->win,
			mlx->img.gro, mlx->p_x * 60, mlx->p_y * 60);
		mlx->p_x --;
		mlx->map[mlx->p_y][mlx->p_x] = 'P';
		mlx_put_image_to_window(mlx->mlx, mlx->win,
			mlx->img.p_1, mlx->p_x * 60, mlx->p_y * 60);
		mlx->nb_move += 1;
		print_counter(mlx);
		if (mlx->p_y  == mlx->spike_y && mlx->p_x + 1 == mlx->spike_x)
			spike_close(mlx, mlx->p_x + 1, mlx->p_y);
	}
}

void	move_s(t_mlx *mlx)
{
	if (mlx->map[mlx->p_y + 1][mlx->p_x] == '0' ||
		mlx->map[mlx->p_y + 1][mlx->p_x] == 'C' ||
		mlx->map[mlx->p_y + 1][mlx->p_x] == 'E')
	{
		if (mlx->map[mlx->p_y + 1][mlx->p_x] == 'E')
			try_escape(mlx);
		if (mlx->map[mlx->p_y + 1][mlx->p_x] == 'C')
		{
			mlx->collec --;
			if (mlx->collec == 0)
				spike_open(mlx);
		}
		mlx->map[mlx->p_y][mlx->p_x] = '0';
		mlx_put_image_to_window(mlx->mlx, mlx->win,
			mlx->img.gro, mlx->p_x * 60, mlx->p_y * 60);
		mlx->p_y ++;
		mlx->map[mlx->p_y][mlx->p_x] = 'P';
		mlx_put_image_to_window(mlx->mlx, mlx->win,
			mlx->img.p_1, mlx->p_x * 60, mlx->p_y * 60);
		mlx->nb_move += 1;
		print_counter(mlx);
		if (mlx->p_y - 1  == mlx->spike_y && mlx->p_x == mlx->spike_x)
			spike_close(mlx, mlx->p_x, mlx->p_y - 1);
	}
}

void	move_d(t_mlx *mlx)
{
	if (mlx->map[mlx->p_y][mlx->p_x + 1] == '0' ||
		mlx->map[mlx->p_y][mlx->p_x + 1] == 'C' ||
		mlx->map[mlx->p_y][mlx->p_x + 1] == 'E')
	{
		if (mlx->map[mlx->p_y][mlx->p_x + 1] == 'E')
			try_escape(mlx);
		if (mlx->map[mlx->p_y][mlx->p_x + 1] == 'C')
		{
			mlx->collec --;
			if (mlx->collec == 0)
				spike_open(mlx);
		}
		mlx->map[mlx->p_y][mlx->p_x] = '0';
		mlx_put_image_to_window(mlx->mlx, mlx->win,
			mlx->img.gro, mlx->p_x * 60, mlx->p_y * 60);
		mlx->p_x ++;
		mlx->map[mlx->p_y][mlx->p_x] = 'P';
		mlx_put_image_to_window(mlx->mlx, mlx->win,
			mlx->img.p_1, mlx->p_x * 60, mlx->p_y * 60);
		mlx->nb_move += 1;
		print_counter(mlx);
		if (mlx->p_y  == mlx->spike_y && mlx->p_x - 1 == mlx->spike_x)
			spike_close(mlx, mlx->p_x - 1, mlx->p_y);
	}
}
