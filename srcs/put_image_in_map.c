/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image_in_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:51:22 by niromano          #+#    #+#             */
/*   Updated: 2023/07/12 18:13:49 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	put_image_in_case(t_mlx *mlx, int i, int j)
{
	int	case_x;
	int	case_y;

	case_y = i * 60;
	case_x = j * 60;
	if (mlx->map[i][j] == '0')
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img_0, case_x, case_y);
	else if (mlx->map[i][j] == '1')
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img_1, case_x, case_y);
	else if (mlx->map[i][j] == '2')
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img_2, case_x, case_y);
	else if (mlx->map[i][j] == 'P')
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img_p, case_x, case_y);
	else if (mlx->map[i][j] == 'C')
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img_c, case_x, case_y);
	else if (mlx->map[i][j] == 'E')
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img_e, case_x, case_y);
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
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img_counter, 5, 5);
	mlx_string_put(mlx->mlx, mlx->win, 15, 25, 0xFFFFFF, "Number of steps :");
	mlx_string_put(mlx->mlx, mlx->win, 15, 45, 0xFFFFFF, "Remaining Orbs :");
	mlx_string_put(mlx->mlx, mlx->win, 120, 25, 0x2ECC71, "0");
	nb = ft_itoa(mlx->collectibles);
	if (nb == NULL)
		error_malloc_all(mlx);
	mlx_string_put(mlx->mlx, mlx->win, 120, 45, 0xF39C12, nb);
	free(nb);
}
