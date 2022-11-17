/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_collectible_count.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:08:31 by minseok2          #+#    #+#             */
/*   Updated: 2022/11/17 11:09:35 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	init_collectible_count(t_game *game)
{
	t_idx	idx;

	ft_memset(&idx, 0, sizeof(t_idx));
	game->collectible_count = 0;
	while (idx.row < game->map_size.row)
	{
		idx.col = 0;
		while (idx.col < game->map_size.col)
		{
			if (game->map[idx.row][idx.col] == COLLECTIBLE)
				game->collectible_count++;
			idx.col++;
		}
		idx.row++;
	}
}
