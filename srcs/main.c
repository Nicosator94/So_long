/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 09:42:01 by niromano          #+#    #+#             */
/*   Updated: 2023/07/12 06:55:04 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	clear_all(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img_0);
	mlx_destroy_image(mlx->mlx, mlx->img_1);
	mlx_destroy_image(mlx->mlx, mlx->img_2);
	mlx_destroy_image(mlx->mlx, mlx->img_p);
	mlx_destroy_image(mlx->mlx, mlx->img_c);
	mlx_destroy_image(mlx->mlx, mlx->img_e);
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
	free_mat(mlx->map);
	exit(EXIT_SUCCESS);
	return (0);
}

int	input(int key, t_mlx *mlx)
{
	if (key == XK_Escape)
		clear_all(mlx);
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

void	init_map(t_mlx *mlx)
{
	int	x;
	int	y;

	x = ft_strlen(mlx->map[0]) - 1;
	y = 0;
	while (mlx->map[y] != NULL)
		y ++;
	mlx->len_w_x = x * 60;
	mlx->len_w_y = y * 60;
	if (mlx->len_w_x > 1920 || mlx->len_w_y > 1020)
		error_len_of_map(mlx);
}

void	border_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[0][j] != '\n')
		map[0][j++] = '2';
	while (map[i + 1] != NULL)
	{
		map[i][0] = '2';
		map[i][ft_strlen(map[i]) - 2] = '2';
		i ++;
	}
	j = 0;
	while (map[i][j] != '\0')
		map[i][j++] = '2';
}

int	main(int argc, char *argv[])
{
	t_mlx	mlx;

	// DATA
	mlx.p_x = 1;
	mlx.p_y = 1;
	mlx.spike_x = 7;
	mlx.spike_y = 1;
	mlx.collectibles = 5;

	check_img();
	mlx.map = init_all_line(argc, argv);
	parsing_map(mlx.map);
	border_map(mlx.map);
	mlx.mlx = mlx_init();
	init_map(&mlx);
	mlx.win = mlx_new_window(mlx.mlx, mlx.len_w_x, mlx.len_w_y, "So_long");
	set_img(&mlx);
	put_image_in_map(&mlx);
	mlx_hook(mlx.win, KeyPress, KeyPressMask, input, &mlx);
	mlx_hook(mlx.win, 17, 0, clear_all, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
