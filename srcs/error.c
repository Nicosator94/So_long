/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 09:22:59 by niromano          #+#    #+#             */
/*   Updated: 2023/07/10 15:47:39 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_lstclear_content(t_list **lst)
{
	t_list	*temp;

	if (lst == NULL)
		return ;
	while (*lst != NULL)
	{
		temp = (*lst)->next;
		free((*lst)->content);
		ft_lstdelone(*lst);
		*lst = temp;
	}
}

void	free_mat(char **mat)
{
	int	i;

	i = 0;
	while (mat[i] != NULL)
	{
		free(mat[i]);
		i ++;
	}
	free(mat);
}

void	error_malloc_list(t_list *list)
{
	ft_putstr_fd("Malloc failed !\n", 2);
	ft_lstclear_content(&list);
	exit(EXIT_FAILURE);
}

void	error_malloc_matrix(char **temp, char **map)
{
	if (temp != NULL)
		free_mat(temp);
	free_mat(map);
	ft_putstr_fd("Malloc failed !\n", 2);
	exit(EXIT_FAILURE);
}
