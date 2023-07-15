/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_counter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 18:00:58 by niromano          #+#    #+#             */
/*   Updated: 2023/07/15 03:07:27 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_counter(t_mlx *mlx)
{
	char	*nb;

	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.counter, 5, 5);
	mlx_string_put(mlx->mlx, mlx->win, 15, 25, 0xFFFFFF, "Number of steps :");
	mlx_string_put(mlx->mlx, mlx->win, 15, 45, 0xFFFFFF, "Remaining Orbs :");
	nb = ft_itoa(mlx->nb_move);
	if (nb == NULL)
		error_malloc_all(mlx);
	if (mlx->nb_move < 50)
		mlx_string_put(mlx->mlx, mlx->win, 120, 25, 0x2ECC71, nb);
	else if (mlx->nb_move >= 50 && mlx->nb_move < 100)
		mlx_string_put(mlx->mlx, mlx->win, 120, 25, 0xF39C12, nb);
	else if (mlx->nb_move >= 100)
		mlx_string_put(mlx->mlx, mlx->win, 120, 25, 0xFF0033, nb);
	free(nb);
	nb = ft_itoa(mlx->collec);
	if (nb == NULL)
		error_malloc_all(mlx);
	if (mlx->collec == 0)
		mlx_string_put(mlx->mlx, mlx->win, 120, 45, 0x2ECC71, nb);
	else
		mlx_string_put(mlx->mlx, mlx->win, 120, 45, 0xF39C12, nb);
	free(nb);
}
