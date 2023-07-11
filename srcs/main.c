/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 09:42:01 by niromano          #+#    #+#             */
/*   Updated: 2023/07/11 07:40:40 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	input(int key, t_mlx *mlx)
{
	if (key == XK_Escape)
	{
		mlx_destroy_image(mlx->mlx, mlx->img_0);
		mlx_destroy_image(mlx->mlx, mlx->img_1);
		mlx_destroy_image(mlx->mlx, mlx->img_p);
		mlx_destroy_image(mlx->mlx, mlx->img_c);
		mlx_destroy_image(mlx->mlx, mlx->img_e);
		mlx_destroy_window(mlx->mlx, mlx->win);
		mlx_destroy_display(mlx->mlx);
		free(mlx->mlx);
		free_mat(mlx->map);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	input_nothing(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img_0);
	mlx_destroy_image(mlx->mlx, mlx->img_1);
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

void	error_len_of_map(t_mlx *mlx)
{
	ft_putstr_fd("The map is too big !\n", 2);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
	free_mat(mlx->map);
	exit(EXIT_FAILURE);
}

void	init_map(t_mlx *mlx, char *map)
{
	char	*s;
	int		fd;
	int		x;
	int		y;

	fd = open(map, O_RDONLY);
	s = get_next_line(fd);
	x = ft_strlen(s) - 1;
	y = 0;
	while (s != NULL)
	{
		y ++;
		free(s);
		s = get_next_line(fd);
	}
	mlx->len_w_x = x * 60;
	mlx->len_w_y = y * 60;
	close(fd);
	if (x > 32 || y > 16)
		error_len_of_map(mlx);
}

int	main(int argc, char *argv[])
{
	t_mlx	mlx;

	mlx.map = init_all_line(argc, argv);
	parsing_map(mlx.map);
	mlx.mlx = mlx_init();
	init_map(&mlx, argv[argc - 1]);
	mlx.win = mlx_new_window(mlx.mlx, mlx.len_w_x, mlx.len_w_y, "So_long");
	set_img(&mlx);
	put_image_in_map(&mlx);
	mlx_hook(mlx.win, KeyPress, KeyPressMask, input, &mlx);
	mlx_hook(mlx.win, 17, 0, input_nothing, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
