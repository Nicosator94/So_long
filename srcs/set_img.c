/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:57:55 by niromano          #+#    #+#             */
/*   Updated: 2023/07/13 20:43:03 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	set_img(t_mlx *mlx)
{
	char	*path;
	int		x;
	int		y;

	path = "./image/ground.xpm";
	mlx->img_0 = mlx_xpm_file_to_image(mlx->mlx, path, &x, &y);
	path = "./image/box.xpm";
	mlx->img_1 = mlx_xpm_file_to_image(mlx->mlx, path, &x, &y);
	path = "./image/wall.xpm";
	mlx->img_2 = mlx_xpm_file_to_image(mlx->mlx, path, &x, &y);
	path = "./image/neon_1.xpm";
	mlx->img_p = mlx_xpm_file_to_image(mlx->mlx, path, &x, &y);
	path = "./image/orb.xpm";
	mlx->img_c = mlx_xpm_file_to_image(mlx->mlx, path, &x, &y);
	path = "./image/spike.xpm";
	mlx->img_e = mlx_xpm_file_to_image(mlx->mlx, path, &x, &y);
	path = "./image/spike_o.xpm";
	mlx->img_e_o = mlx_xpm_file_to_image(mlx->mlx, path, &x, &y);
	path = "./image/counter.xpm";
	mlx->img_counter = mlx_xpm_file_to_image(mlx->mlx, path, &x, &y);
}
