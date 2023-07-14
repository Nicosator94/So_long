/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 06:55:26 by niromano          #+#    #+#             */
/*   Updated: 2023/07/15 01:15:26 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	error_image(char *s)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd("Image \"", 2);
	ft_putstr_fd(s, 2);
	ft_putstr_fd("\" was not found !\n", 2);
}

int	check_one_by_one(char *s, int trigger)
{
	int	fd;

	fd = open(s, O_RDONLY);
	if (fd == -1)
	{
		error_image(s);
		trigger = 1;
	}
	else
		close(fd);
	if (trigger == 1)
		return (1);
	return (0);
}

void	check_img(char **env)
{
	int	trigger;

	if (env[0] == NULL)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("The environment is not accessible, ", 2);
		ft_putstr_fd("the images cannot be found !\n", 2);
		exit(EXIT_FAILURE);
	}
	trigger = 0;
	trigger = check_one_by_one("./image/ground.xpm", trigger);
	trigger = check_one_by_one("./image/box.xpm", trigger);
	trigger = check_one_by_one("./image/wall.xpm", trigger);
	trigger = check_one_by_one("./image/neon_1.xpm", trigger);
	trigger = check_one_by_one("./image/neon_2.xpm", trigger);
	trigger = check_one_by_one("./image/orb.xpm", trigger);
	trigger = check_one_by_one("./image/spike_c.xpm", trigger);
	trigger = check_one_by_one("./image/spike_o.xpm", trigger);
	trigger = check_one_by_one("./image/counter.xpm", trigger);
	if (trigger == 1)
		exit(EXIT_FAILURE);
}
