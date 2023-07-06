/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 09:42:01 by niromano          #+#    #+#             */
/*   Updated: 2023/07/06 13:44:32 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	input(int key, t_mlx *mlx)
{
	if (key == XK_Escape)
	{
		mlx_destroy_image(mlx->mlx, mlx->img);
		mlx_destroy_window(mlx->mlx, mlx->win);
		mlx_destroy_display(mlx->mlx);
		free(mlx->mlx);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

void	init_map(t_mlx *mlx, char *map)
{
	char	*s;
	int		fd;
	int		x;
	int		y;

	fd = open(map, O_RDONLY);
	s = get_next_line(fd);
	x = ft_strlen(s);
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
}

int	main(int argc, char *argv[])
{
	t_mlx	mlx;
	int		x = 0;
	int		y = 0;
	int		case_x = 0;
	int		case_y = 0;

	mlx.path_case_img = "./image/among6.xpm";
	mlx.mlx = mlx_init();
	init_map(&mlx, argv[argc - 1]);
	mlx.win = mlx_new_window(mlx.mlx, mlx.len_w_x, mlx.len_w_y, "So_long");
	mlx.img = mlx_xpm_file_to_image(mlx.mlx, mlx.path_case_img, &x, &y);
	if (mlx.img == NULL)
		ft_printf("Image Failed\n");
	while (case_x < mlx.len_w_x)
	{
		while (case_y < mlx.len_w_y)
		{
			mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, case_x, case_y);
			case_y += 60;
		}
		case_y = 0;
		case_x += 60;
	}
	mlx_hook(mlx.win, KeyPress, KeyPressMask, input, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}