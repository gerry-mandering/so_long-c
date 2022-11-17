/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map_to_char_array.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 23:01:32 by minseok2          #+#    #+#             */
/*   Updated: 2022/11/16 23:28:39 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

char	**copy_map_to_char_array(t_list *map_lst, const t_idx map_size)
{
	t_idx		idx;
	t_node		*current_node;
	char		**map;

	ft_memset(&idx, 0, sizeof(t_idx));
	current_node = map_lst->head->next;
	map = (char **)ft_calloc(map_size.col, sizeof(char *));
	while (idx.row < map_size.row)
		*(map + idx.row++) = (char *)ft_calloc(map_size.col + 1, sizeof(char));
	ft_memset(&idx, 0, sizeof(t_idx));
	while (current_node->next != NULL)
	{
		idx.col = 0;
		while (current_node->line[idx.col])
		{
			map[idx.row][idx.col] = current_node->line[idx.col];
			idx.col++;
		}
		current_node = current_node->next;
		idx.row++;
	}
	return (map);
}
