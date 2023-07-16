/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 01:22:05 by niromano          #+#    #+#             */
/*   Updated: 2023/07/16 12:50:45 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	input(int key, t_mlx *mlx)
{
	if (key == XK_Escape)
		clear_all_success(mlx);
	if (key == 'w' || key == 'z' || key == XK_Up)
		move_w(mlx);
	if (key == 'a' || key == 'q' || key == XK_Left)
		move_a(mlx);
	if (key == 's' || key == XK_Down)
		move_s(mlx);
	if (key == 'd' || key == XK_Right)
		move_d(mlx);
	return (0);
}
