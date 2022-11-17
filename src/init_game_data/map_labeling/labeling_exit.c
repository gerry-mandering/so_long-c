/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   labeling_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 02:24:10 by minseok2          #+#    #+#             */
/*   Updated: 2022/11/17 03:16:51 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"

void	labeling_exit(int **map, t_list *map_lst)
{
	t_idx	idx;
	t_node	*current_node;

	ft_memset(&idx, 0, sizeof(t_idx));
	current_node = map_lst->head->next;
	while (current_node->next != NULL)
	{
		idx.col = 0;
		while (current_node->line[idx.col])
		{
			if (current_node->line[idx.col] == C_EXIT)
				map[idx.row][idx.col] = EXIT;
			idx.col++;
		}
		current_node = current_node->next;
		idx.row++;
	}
}
