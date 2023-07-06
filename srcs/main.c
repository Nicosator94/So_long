/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 09:42:01 by niromano          #+#    #+#             */
/*   Updated: 2023/07/06 12:22:58 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	exit_end(int key)
{
	if (key == XK_Escape)
	{
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	main(void)
{
	void	*mlx;
	void	*img;
	void	*mlx_win;
	char	*path_img;
	int		x = 0;
	int		y = 0;
	int		case_x = 0;
	int		case_y = 0;
	
	path_img = "./image/among2.xpm";
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 800, 600, "So_long");
	img = mlx_xpm_file_to_image(mlx, path_img, &x, &y);
	if (img == NULL)
		ft_printf("Image Failed\n");
	while (case_y < 600)
	{
		while (case_x < 800)
		{
			mlx_put_image_to_window(mlx, mlx_win, img, case_x, case_y);
			case_x += 50;
		}
		case_x = 0;
		case_y += 50;
	}
	mlx_hook(mlx_win, KeyPress, KeyPressMask, exit_end, NULL);
	mlx_loop(mlx);
	return (0);
}