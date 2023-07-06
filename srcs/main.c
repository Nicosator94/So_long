/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 09:42:01 by niromano          #+#    #+#             */
/*   Updated: 2023/07/06 07:49:06 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char *argv[])
{
	void	*mlx;
	void	*img;
	
	mlx = mlx_init();
	img = mlx_new_image(mlx, 960, 540);
	mlx_loop(mlx);
	if (argc && argv) {}
	ft_printf("C'est fini, youpi !\n");
	return (0);
}