/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_rectangular_shape.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 23:32:11 by minseok2          #+#    #+#             */
/*   Updated: 2022/11/17 01:27:45 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	validate_rectangular_shape(t_list *map_lst, const t_idx map_size)
{
	t_node	*current_node;

	current_node = map_lst->head->next;
	if (map_size.row < 3 || map_size.col < 3)
		ft_exit("wrong map\nError", STDERR_FILENO, EXIT_FAILURE);
	while (current_node->next != NULL)
	{
		if ((int)ft_strlen(current_node->line) != map_size.col)
			ft_exit("wrong map\nError", STDERR_FILENO, EXIT_FAILURE);
		current_node = current_node->next;
	}
}
