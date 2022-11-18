/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   labeling_tree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 02:47:01 by minseok2          #+#    #+#             */
/*   Updated: 2022/11/18 14:40:09 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"

static int	count_continuous_wall(char **map_chr, t_idx map_size, t_idx idx)
{
	int		count;

	count = 0;
	while (idx.row < map_size.row - 1)
	{
		if (map_chr[idx.row][idx.col] == C_WALL)
			count++;
		else
			break ;
		idx.row++;
	}
	return (count);
}

static void	labeling_single_tree(int **map, char **map_chr, t_idx idx)
{
	map[idx.row][idx.col] = TREE_TOP;
	map[idx.row + 1][idx.col] = TREE_BOTTOM;
	map_chr[idx.row][idx.col] = C_TREE;
	map_chr[idx.row + 1][idx.col] = C_TREE;
}

static void	labeling_double_tree(int **map, char **map_chr, t_idx idx)
{
	map[idx.row][idx.col] = TREE_TOP;
	map[idx.row + 1][idx.col] = TREE_MID;
	map[idx.row + 2][idx.col] = TREE_BOTTOM;
	map_chr[idx.row][idx.col] = C_TREE;
	map_chr[idx.row + 1][idx.col] = C_TREE;
	map_chr[idx.row + 2][idx.col] = C_TREE;
}

void	labeling_tree(int **map, t_list *map_lst, t_idx map_size)
{
	int		count;
	t_idx	idx;
	char	**map_chr;

	count = 0;
	idx.row = 1;
	map_chr = copy_map_to_char_array(map_lst, map_size);
	while (idx.row < map_size.row - 2)
	{
		idx.col = 1;
		while (idx.col < map_size.col - 1)
		{
			count = count_continuous_wall(map_chr, map_size, idx);
			if (count == 2)
				labeling_single_tree(map, map_chr, idx);
			else if (count >= 3)
				labeling_double_tree(map, map_chr, idx);
			idx.col++;
		}
		idx.row++;
	}
	free_char_map(map_chr, map_size);
}
