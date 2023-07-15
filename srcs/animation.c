/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 01:17:20 by niromano          #+#    #+#             */
/*   Updated: 2023/07/15 03:05:13 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	animation(t_mlx *mlx)
{
	int	p_x;
	int	p_y;
	int	s_x;
	int	s_y;

	p_x = mlx->p_x * 60;
	p_y = mlx->p_y * 60;
	s_x = mlx->spike_x * 60;
	s_y = mlx->spike_y * 60;
	if (mlx->timer == 0)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.p_1, p_x, p_y);
	else if (mlx->timer == 1500)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.p_2, p_x, p_y);
	else if (mlx->timer == 3000)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.p_3, p_x, p_y);
	if (!(p_x == s_x && p_y == s_y))
	{
		if (mlx->timer == 0 && mlx->collectibles != 0)
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.e_c, s_x, s_y);
		else if (mlx->timer == 3500 && mlx->collectibles != 0)
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.e_o, s_x, s_y);
	}
	if (mlx->timer++ > 4500)
		mlx->timer = 0;
	return (0);
}
