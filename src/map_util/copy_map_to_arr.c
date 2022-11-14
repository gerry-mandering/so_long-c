/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map_to_arr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 21:45:08 by minseok2          #+#    #+#             */
/*   Updated: 2022/11/14 13:58:27 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	copy_map_to_arr(char ***arr_map, t_list *list_map, t_coord *map_size)
{
	int		i;
	int		j;
	t_node	*current_node;

	i = 0;
	current_node = list_map->head->next;
	(*arr_map) = (char **)ft_malloc(sizeof(char *) * (map_size->col));
	while (i < map_size->col)
		*((*arr_map) + i++) = (char *)ft_calloc((map_size->row) + 1, \
				sizeof(char));
	i = 0;
	while (current_node->next != NULL)
	{
		j = 0;
		while ((current_node->line)[j])
		{
			(*arr_map)[i][j] = current_node->line[j];
			j++;
		}
		current_node = current_node->next;
		i++;
	}
}

void	move_map_to_arr(char ***arr_map, t_list *list_map, t_coord *map_size)
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
