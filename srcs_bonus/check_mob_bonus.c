/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mob_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 14:31:51 by niromano          #+#    #+#             */
/*   Updated: 2023/07/16 14:53:06 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	check_mob(t_mlx *mlx, int trigger_y, int trigger_x)
{
	mlx->map[mlx->p_y][mlx->p_x] = '0';
	mlx_put_image_to_window(mlx->mlx, mlx->win,
		mlx->img.gro, mlx->p_x * 60, mlx->p_y * 60);
	mlx->p_y += trigger_y;
	mlx->p_x += trigger_x;
	mlx->map[mlx->p_y][mlx->p_x] = 'X';
	mlx_put_image_to_window(mlx->mlx, mlx->win,
		mlx->img.death, mlx->p_x * 60, mlx->p_y * 60);
	ft_printf("You died !\n");
	ft_printf("You can leave and retry !\n");
}
