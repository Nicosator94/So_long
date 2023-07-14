/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 09:42:01 by niromano          #+#    #+#             */
/*   Updated: 2023/07/15 01:23:01 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char *argv[], char **env)
{
	t_mlx	mlx;

	check_img(env);
	mlx.map = init_all_line(argc, argv);
	parsing_map(mlx.map);
	border_map(mlx.map);
	mlx.mlx = mlx_init();
	init_map(&mlx);
	set_data(&mlx);
	mlx.win = mlx_new_window(mlx.mlx, mlx.len_w_x, mlx.len_w_y, "So_long");
	set_img(&mlx);
	put_image_in_map(&mlx);
	mlx_hook(mlx.win, KeyPress, KeyPressMask, input, &mlx);
	mlx_hook(mlx.win, 17, 0, clear_all_success, &mlx);
	mlx_loop_hook(mlx.mlx, animation, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
