/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:57:55 by niromano          #+#    #+#             */
/*   Updated: 2023/07/10 16:27:29 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	set_img(t_mlx *mlx)
{
	char	*path;
	int		x = 0;
	int		y = 0;

	path = "./image/jaune.xpm";
	mlx->img_0 = mlx_xpm_file_to_image(mlx->mlx, path, &x, &y);
	if (mlx->img_0 == NULL)
		ft_printf("Image Failed\n");
	path = "./image/jaune.xpm";
	mlx->img_1 = mlx_xpm_file_to_image(mlx->mlx, path, &x, &y);
	if (mlx->img_1 == NULL)
		ft_printf("Image Failed\n");
	path = "./image/neon_1.xpm";
	mlx->img_p = mlx_xpm_file_to_image(mlx->mlx, path, &x, &y);
	if (mlx->img_p == NULL)
		ft_printf("Image Failed\n");
	path = "./image/jaune.xpm";
	mlx->img_c = mlx_xpm_file_to_image(mlx->mlx, path, &x, &y);
	if (mlx->img_c == NULL)
		ft_printf("Image Failed\n");
	path = "./image/jaune.xpm";
	mlx->img_e = mlx_xpm_file_to_image(mlx->mlx, path, &x, &y);
	if (mlx->img_e == NULL)
		ft_printf("Image Failed\n");
}
