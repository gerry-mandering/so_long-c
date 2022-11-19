/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 01:05:55 by minseok2          #+#    #+#             */
/*   Updated: 2022/11/18 19:38:35 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static t_idx	get_player_position(char **map, const t_idx map_size)
{
	t_idx	player_pos;

	ft_memset(&player_pos, 0, sizeof(t_idx));
	while (player_pos.row < map_size.row)
	{
		player_pos.col = 0;
		while (player_pos.col < map_size.col)
		{
			if (map[player_pos.row][player_pos.col] == C_PLAYER)
				return (player_pos);
			player_pos.col++;
		}
		player_pos.row++;
	}
	return (player_pos);
}

static void	flood_fill(char **map, int row, int col, const t_idx map_size)
{
	if (row < 0 || col < 0)
		return ;
	else if (row == map_size.row || col == map_size.col)
		return ;
	else if (map[row][col] == C_WALL || map[row][col] == C_FLOODED)
		return ;
	map[row][col] = C_FLOODED;
	flood_fill(map, row - 1, col, map_size);
	flood_fill(map, row + 1, col, map_size);
	flood_fill(map, row, col - 1, map_size);
	flood_fill(map, row, col + 1, map_size);
}

static void	check_flooded(char **map, const t_idx map_size)
{
	t_idx	idx;

	ft_memset(&idx, 0, sizeof(t_idx));
	while (idx.row < map_size.row)
	{
		idx.col = 0;
		while (idx.col < map_size.col)
		{
			if (map[idx.row][idx.col] == C_COLLECTIBLE || \
					map[idx.row][idx.col] == C_EXIT)
				ft_exit("Error\nno valid path", STDERR_FILENO, EXIT_FAILURE);
			idx.col++;
		}
		idx.row++;
	}
}

void	validate_path(char **map, const t_idx map_size)
{
	t_idx	player_pos;

	player_pos = get_player_position(map, map_size);
	flood_fill(map, player_pos.row, player_pos.col, map_size);
	check_flooded(map, map_size);
}
