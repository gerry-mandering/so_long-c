/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_rectangular_shape.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 21:33:26 by minseok2          #+#    #+#             */
/*   Updated: 2022/11/13 21:33:47 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	validate_rectangular_shape(t_list *list_map)
{
	t_node	*current_node;
	int		colum_size;
	int		row_size;

	current_node = list_map->head->next;
	colum_size = 0;
	row_size = ft_strlen(current_node->line);
	if (row_size < 3)
		ft_exit("wrong map\nError", STDERR_FILENO, EXIT_FAILURE);
	while (current_node->next != NULL)
	{
		if ((int)ft_strlen(current_node->line) != row_size)
			ft_exit("wrong map\nError", STDERR_FILENO, EXIT_FAILURE);
		current_node = current_node->next;
		colum_size++;
	}
	if (colum_size < 3)
		ft_exit("wrong map\nError", STDERR_FILENO, EXIT_FAILURE);
}
