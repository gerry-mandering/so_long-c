/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_surrounding_wall.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 00:58:30 by minseok2          #+#    #+#             */
/*   Updated: 2022/11/18 19:39:07 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	validate_surrounding_wall(char **map, const t_idx map_size)
{
	t_idx	idx;

	ft_memset(&idx, 0, sizeof(t_idx));
	while (idx.row < map_size.row)
	{
		if (map[idx.row][0] != C_WALL || \
				map[idx.row][map_size.col - 1] != C_WALL)
			ft_exit("Error\nwrong wall in map", STDERR_FILENO, EXIT_FAILURE);
		idx.row++;
	}
	while (idx.col < map_size.col)
	{
		if (map[0][idx.col] != C_WALL || \
				map[map_size.row - 1][idx.col] != C_WALL)
			ft_exit("Error\nwrong wall in map", STDERR_FILENO, EXIT_FAILURE);
		idx.col++;
	}
}
