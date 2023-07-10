/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 09:39:06 by niromano          #+#    #+#             */
/*   Updated: 2023/07/10 13:40:37 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	int		len_w_x;
	int		len_w_y;
	char	*path_case_img;
}	t_mlx;

typedef struct s_data
{
	int	i;
}	t_data;

char	**init_all_line(int argc, char *argv[]);

void	parsing_map(char **map);
void	error_map(char **map, int trigger);
void	check_escape(char **map);
void	check_player(char **map);
void	check_collectibles(char **map);
void	check_if_possible_to_end(char **map);

void	free_mat(char **mat);
void	ft_lstclear_content(t_list **lst);
void	error_malloc_list(t_list *list);

#endif