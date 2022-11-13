/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map_to_arr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 21:45:08 by minseok2          #+#    #+#             */
/*   Updated: 2022/11/13 21:45:19 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	copy_map_to_arr(char ***arr_map, t_list *list_map, t_coord *map_size)
{
	int		node_index;
	t_node	*current_node;

	(*arr_map) = (char **)ft_malloc(sizeof(char *) * (map_size->col));
	node_index = 0;
	current_node = list_map->head->next;
	while (current_node->next != NULL)
	{
		(*arr_map)[node_index] = current_node->line;
		current_node = current_node->next;
		node_index++;
	}
}
