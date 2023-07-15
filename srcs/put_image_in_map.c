/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image_in_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:51:22 by niromano          #+#    #+#             */
/*   Updated: 2023/07/15 21:57:23 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	put_image_in_case(t_mlx *mlx, int i, int j)
{
	int	x;
	int	y;

	y = i * 60;
	x = j * 60;
	if (mlx->map[i][j] == '0')
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.gro, x, y);
	else if (mlx->map[i][j] == '1')
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.box, x, y);
	else if (mlx->map[i][j] == '2')
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.wal, x, y);
	else if (mlx->map[i][j] == 'P')
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.p_1, x, y);
	else if (mlx->map[i][j] == 'C')
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.o, x, y);
	else if (mlx->map[i][j] == 'E')
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.e_c, x, y);
}

void	put_image_in_map(t_mlx *mlx)
{
	int		i;
	int		j;
	char	*nb;

	i = 0;
	j = 0;
	while (mlx->map[i] != NULL)
	{
		while (mlx->map[i][j] != '\0')
		{
			put_image_in_case(mlx, i, j);
			j ++;
		}
		j = 0;
		i ++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.counter, 5, 5);
	mlx_string_put(mlx->mlx, mlx->win, 15, 25, 0xFFFFFF, "Number of steps :");
	mlx_string_put(mlx->mlx, mlx->win, 15, 45, 0xFFFFFF, "Remaining Orbs :");
	mlx_string_put(mlx->mlx, mlx->win, 120, 25, 0x2ECC71, "0");
	nb = ft_itoa(mlx->collec);
	if (nb == NULL)
		error_malloc_all(mlx);
	mlx_string_put(mlx->mlx, mlx->win, 120, 45, 0xF39C12, nb);
	free(nb);
}
