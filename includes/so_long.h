/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 09:39:06 by niromano          #+#    #+#             */
/*   Updated: 2023/07/15 02:55:13 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"

typedef struct s_image
{
	void	*gro;
	void	*box;
	void	*wal;
	void	*p_1;
	void	*p_2;
	void	*p_3;
	void	*o;
	void	*e_c;
	void	*e_o;
	void	*counter;
}	t_image;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	int		len_w_x;
	int		len_w_y;
	char	**map;
	int		p_x;
	int		p_y;
	int		collectibles;
	int		spike_x;
	int		spike_y;
	int		nb_move;
	int		timer;
	t_image	img;
}	t_mlx;

char	**init_all_line(int argc, char *argv[]);

void	parsing_map(char **map);
void	border_map(char **map);
void	error_map(char **map, int trigger);
void	check_escape(char **map);
void	check_player(char **map);
void	check_collectibles(char **map);
void	check_if_possible_to_end(char **map);

void	init_map(t_mlx *mlx);
void	set_data(t_mlx *mlx);

void	check_img(char **env);
void	set_img(t_mlx *mlx);
void	put_image_in_map(t_mlx *mlx);
void	spike_open(t_mlx *mlx);
void	spike_close(t_mlx *mlx, int p_x, int p_y);
void	print_counter(t_mlx *mlx);

int		input(int key, t_mlx *mlx);

void	move_w(t_mlx *mlx);
void	move_a(t_mlx *mlx);
void	move_s(t_mlx *mlx);
void	move_d(t_mlx *mlx);

int		animation(t_mlx *mlx);

int		clear_all_success(t_mlx *mlx);
int		clear_all_failure(t_mlx *mlx);

void	free_mat(char **mat);
void	ft_lstclear_content(t_list **lst);
void	error_malloc_list(t_list *list);
void	error_malloc_matrix(char **temp, char **map);
void	error_len_of_map(t_mlx *mlx);
void	error_malloc_all(t_mlx *mlx);

#endif