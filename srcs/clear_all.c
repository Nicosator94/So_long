/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 18:08:11 by niromano          #+#    #+#             */
/*   Updated: 2023/07/15 01:05:12 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	clear_all_success(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img.gro);
	mlx_destroy_image(mlx->mlx, mlx->img.box);
	mlx_destroy_image(mlx->mlx, mlx->img.wal);
	mlx_destroy_image(mlx->mlx, mlx->img.p_1);
	mlx_destroy_image(mlx->mlx, mlx->img.p_2);
	mlx_destroy_image(mlx->mlx, mlx->img.o_1);
	mlx_destroy_image(mlx->mlx, mlx->img.e_c);
	mlx_destroy_image(mlx->mlx, mlx->img.e_o);
	mlx_destroy_image(mlx->mlx, mlx->img.counter);
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
	free_mat(mlx->map);
	exit(EXIT_SUCCESS);
	return (0);
}

int	clear_all_failure(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img.gro);
	mlx_destroy_image(mlx->mlx, mlx->img.box);
	mlx_destroy_image(mlx->mlx, mlx->img.wal);
	mlx_destroy_image(mlx->mlx, mlx->img.p_1);
	mlx_destroy_image(mlx->mlx, mlx->img.p_2);
	mlx_destroy_image(mlx->mlx, mlx->img.o_1);
	mlx_destroy_image(mlx->mlx, mlx->img.e_c);
	mlx_destroy_image(mlx->mlx, mlx->img.e_o);
	mlx_destroy_image(mlx->mlx, mlx->img.counter);
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
	free_mat(mlx->map);
	exit(EXIT_FAILURE);
	return (0);
}

void	error_malloc_all(t_mlx *mlx)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd("Malloc failed !\n", 2);
	clear_all_failure(mlx);
}
