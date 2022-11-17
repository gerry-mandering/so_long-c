/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_position.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 03:23:42 by minseok2          #+#    #+#             */
/*   Updated: 2022/11/17 10:47:18 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	init_player_position(t_game *game)
{
	t_idx	idx;

	ft_memset(&idx, 0, sizeof(t_idx));
	while (idx.row < game->map_size.row)
	{
		idx.col = 0;
		while (idx.col < game->map_size.col)
		{
			if (game->map[idx.row][idx.col] == PLAYER)
			{
				game->player_pos.row = idx.row;
				game->player_pos.col = idx.col;
				return ;
			}
			idx.col++;
		}
		idx.row++;
	}
}
