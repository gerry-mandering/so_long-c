/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 06:47:06 by minseok2          #+#    #+#             */
/*   Updated: 2022/11/17 10:56:54 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	print_map(t_game *game, t_idx map_size)
{
	int						label;
	t_idx					idx;
	const t_print_label_fp	print_label_fp[TOTAL_LABELS] = \
	{
		p_road, p_exit, p_player_down,
		p_top_left_corner, p_top_right_corner,
		p_bottom_left_corner, p_bottom_right_corner,
		p_top_side, p_bottom_side, p_left_side, p_right_side,
		p_tree_top, p_tree_mid, p_tree_bottom,
		p_sign, p_fence, p_bush, p_rock
	};

	ft_memset(&idx, 0, sizeof(t_idx));
	while (idx.row < map_size.row)
	{
		idx.col = 0;
		while (idx.col < map_size.col)
		{
			label = game->map[idx.row][idx.col];
			if (label != COLLECTIBLE)
				(*print_label_fp[label])(game, idx);
			idx.col++;
		}
		idx.row++;
	}
}
