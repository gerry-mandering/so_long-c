/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   labeling_obstacle.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 02:37:28 by minseok2          #+#    #+#             */
/*   Updated: 2022/11/17 02:57:36 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"

static int	get_obstacle_in_order(void)
{
	static int	count;
	const int	obstacle_arr[4] = {SIGN, FENCE, BUSH, ROCK};

	return (obstacle_arr[count++ % 4]);
}

void	labeling_obstacle(int **map, t_list *map_lst)
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
			if (map[idx.row][idx.col] == 0 && \
					current_node->line[idx.col] == C_WALL)
				map[idx.row][idx.col] = get_obstacle_in_order();
			idx.col++;
		}
		idx.row++;
		current_node = current_node->next;
	}
}
