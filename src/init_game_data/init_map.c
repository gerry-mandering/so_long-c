/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 02:07:38 by minseok2          #+#    #+#             */
/*   Updated: 2022/11/17 11:30:15 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static int	**allocate_map_memory(t_idx map_size)
{
	int	i;
	int	**map;

	i = 0;
	map = (int **)ft_calloc(map_size.row, sizeof(int *));
	while (i < map_size.row)
		*(map + i++) = (int *)ft_calloc(map_size.col, sizeof(int));
	return (map);
}

void	init_map(t_game *game)
{
	game->map = allocate_map_memory(game->map_size);
	labeling_road(game->map, &game->map_lst);
	labeling_collectible(game->map, &game->map_lst);
	labeling_exit(game->map, &game->map_lst);
	labeling_player(game->map, &game->map_lst);
	labeling_wall(game->map, game->map_size);
	labeling_tree(game->map, &game->map_lst, game->map_size);
	labeling_obstacle(game->map, &game->map_lst);
}
