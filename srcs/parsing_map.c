/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 08:40:17 by niromano          #+#    #+#             */
/*   Updated: 2023/07/08 11:00:19 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_ext(char *file_name)
{
	char	**mat;
	int		i;

	i = 0;
	mat = ft_split(file_name, '.');
	if (mat == NULL)
	{
		ft_putstr_fd("Error malloc\n", 2);
		exit(EXIT_FAILURE);
	}
	while (mat[i + 1] != NULL)
		i ++;
	if (ft_strncmp(mat[i], "ber", 4) != 0)
	{
		ft_putstr_fd("Extension de map incorrect\n", 2);
		free_mat(mat);
		exit(EXIT_FAILURE);
	}
	free_mat(mat);
}

t_list	*init_temp_list(int map)
{
	t_list	*temp_list;
	t_list	*temp;
	char	*s;

	s = get_next_line(map);
	if (s != NULL)
	{
		temp_list = ft_lstnew(ft_strdup(s));
		if (temp_list->content == NULL)
			error_malloc_list(temp_list);
	}
	while (s != NULL)
	{
		free(s);
		s = get_next_line(map);
		if (s != NULL)
		{
			temp = ft_lstnew(ft_strdup(s));
			if (temp == NULL)
				error_malloc_list(temp_list);
			ft_lstadd_back(&temp_list, temp);
		}
	}
	return (temp_list);
}

char	**fill_line_to_mat(t_list *temp_list)
{
	t_list	*start_list;
	char	**all_line;
	int		i;

	i = 0;
	start_list = temp_list;
	all_line = malloc(sizeof(char *) * (ft_lstsize(start_list) + 1));
	if (all_line == NULL)
		error_malloc_list(start_list);
	while (temp_list != NULL)
	{
		all_line[i] = ft_strdup(temp_list->content);
		if (all_line[i] == NULL)
		{
			free_mat(all_line);
			error_malloc_list(start_list);
		}
		temp_list = temp_list->next;
		i ++;
	}
	ft_lstclear_content(&start_list);
	all_line[i] = NULL;
	return (all_line);
}

char	**get_line(char *file_name)
{
	t_list	*temp_list;
	char	**all_line;
	int		map;

	map = open(file_name, O_RDONLY);
	if (map == -1)
	{
		ft_putstr_fd("Echec de lecture\n", 2);
		exit(EXIT_FAILURE);
	}
	temp_list = init_temp_list(map);
	all_line = fill_line_to_mat(temp_list);
	close(map);
	return (all_line);
}

char	**parsing_map(int argc, char *argv[])
{
	char	**all_line;
	
	if (argc < 2)
	{
		ft_putstr_fd("Insérez une map dans les arguments !\n", 2);
		exit(EXIT_FAILURE);
	}
	check_ext(argv[1]);
	all_line = get_line(argv[1]);
	return (all_line);
}
