/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 01:17:20 by niromano          #+#    #+#             */
/*   Updated: 2023/07/15 01:17:40 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	animation(t_mlx *mlx)
{
	int	x;
	int	y;

	x = mlx->p_x * 60;
	y = mlx->p_y * 60;
	if (mlx->timer == 0)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.p_1, x, y);
	else if (mlx->timer == 2500)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.p_2, x, y);
	mlx->timer ++;
	if (mlx->timer > 5000)
		mlx->timer = 0;
	return (0);
}
