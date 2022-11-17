/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   labeling_wall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 02:29:07 by minseok2          #+#    #+#             */
/*   Updated: 2022/11/17 02:36:44 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"

static void	labeling_corner_wall(int **map, t_idx map_size)
{
	map[0][0] = TOP_LEFT_CORNER;
	map[0][map_size.col - 1] = TOP_RIGHT_CORNER;
	map[map_size.row - 1][0] = BOTTOM_LEFT_CORNER;
	map[map_size.row - 1][map_size.col - 1] = BOTTOM_RIGHT_CORNER;
}

static void	labeling_side_wall(int **map, t_idx map_size)
{
	int	i;

	i = 1;
	while (i < map_size.row - 1)
	{
		map[i][0] = LEFT_SIDE;
		map[i][map_size.col - 1] = RIGHT_SIDE;
		i++;
	}
	i = 1;
	while (i < map_size.col - 1)
	{
		map[0][i] = TOP_SIDE;
		map[map_size.row - 1][i] = BOTTOM_SIDE;
		i++;
	}
}

void	labeling_wall(int **map, t_idx map_size)
{
	labeling_corner_wall(map, map_size);
	labeling_side_wall(map, map_size);
}
