/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 07:38:16 by minseok2          #+#    #+#             */
/*   Updated: 2022/11/17 14:16:15 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	move_player_up(t_game *game, int **map, t_idx *player_pos)
{
	if (map[player_pos->row - 1][player_pos->col] == ROAD || \
			map[player_pos->row - 1][player_pos->col] == COLLECTIBLE)
	{
		if (map[player_pos->row - 1][player_pos->col] == COLLECTIBLE)
			game->collectible_count--;
		p_road(game, *player_pos);
		map[player_pos->row][player_pos->col] = ROAD;
		player_pos->row--;
		p_player_up(game, *player_pos);
		map[player_pos->row][player_pos->col] = PLAYER_UP;
		game->move_count++;
		ft_printf("move_count = %d\n", game->move_count);
	}
	else if (map[player_pos->row - 1][player_pos->col] == EXIT && \
			game->collectible_count == 0)
	{
		game->move_count++;
		ft_printf("move_count = %d\n", game->move_count);
		close_game(game);
	}
}

void	move_player_down(t_game *game, int **map, t_idx *player_pos)
{
	if (map[player_pos->row + 1][player_pos->col] == ROAD || \
			map[player_pos->row + 1][player_pos->col] == COLLECTIBLE)
	{
		if (map[player_pos->row + 1][player_pos->col] == COLLECTIBLE)
			game->collectible_count--;
		p_road(game, *player_pos);
		map[player_pos->row][player_pos->col] = ROAD;
		player_pos->row++;
		p_player_down(game, *player_pos);
		map[player_pos->row][player_pos->col] = PLAYER_DOWN;
		game->move_count++;
		ft_printf("move_count = %d\n", game->move_count);
	}
	else if (map[player_pos->row + 1][player_pos->col] == EXIT && \
			game->collectible_count == 0)
	{
		game->move_count++;
		ft_printf("move_count = %d\n", game->move_count);
		close_game(game);
	}
}

void	move_player_left(t_game *game, int **map, t_idx *player_pos)
{
	if (map[player_pos->row][player_pos->col - 1] == ROAD || \
			map[player_pos->row][player_pos->col - 1] == COLLECTIBLE)
	{
		if (map[player_pos->row][player_pos->col - 1] == COLLECTIBLE)
			game->collectible_count--;
		p_road(game, *player_pos);
		map[player_pos->row][player_pos->col] = ROAD;
		player_pos->col--;
		p_player_left(game, *player_pos);
		map[player_pos->row][player_pos->col] = PLAYER_LEFT;
		game->move_count++;
		ft_printf("move_count = %d\n", game->move_count);
	}
	else if (map[player_pos->row][player_pos->col - 1] == EXIT && \
			game->collectible_count == 0)
	{
		game->move_count++;
		ft_printf("move_count = %d\n", game->move_count);
		close_game(game);
	}
}

void	move_player_right(t_game *game, int **map, t_idx *player_pos)
{
	if (map[player_pos->row][player_pos->col + 1] == ROAD || \
			map[player_pos->row][player_pos->col + 1] == COLLECTIBLE)
	{
		if (map[player_pos->row][player_pos->col + 1] == COLLECTIBLE)
			game->collectible_count--;
		p_road(game, *player_pos);
		map[player_pos->row][player_pos->col] = ROAD;
		player_pos->col++;
		p_player_right(game, *player_pos);
		map[player_pos->row][player_pos->col] = PLAYER_RIGHT;
		game->move_count++;
		ft_printf("move_count = %d\n", game->move_count);
	}
	else if (map[player_pos->row][player_pos->col + 1] == EXIT && \
			game->collectible_count == 0)
	{
		game->move_count++;
		ft_printf("move_count = %d\n", game->move_count);
		close_game(game);
	}
}
