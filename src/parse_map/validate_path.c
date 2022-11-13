/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 21:42:58 by minseok2          #+#    #+#             */
/*   Updated: 2022/11/13 21:50:55 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	get_start_coord(t_coord *start_coord, \
		char **arr_map, t_coord *map_size)
{
	int	i;
	int	j;

	i = 0;
	while (i < map_size->col)
	{
		j = 0;
		while (arr_map[i][j] != '\0')
		{
			if (arr_map[i][j] == 'P')
			{
				start_coord->col = i;
				start_coord->row = j;
			}
			j++;
		}
		i++;
	}
}

static void	flood_fill(char **arr_map, int col, int row, t_coord *map_size)
{
	if (col < 0 || row < 0)
		return ;
	else if (col == map_size->col || row == map_size->row)
		return ;
	else if (arr_map[col][row] == '1' || arr_map[col][row] == 'F')
		return ;
	arr_map[col][row] = 'F';
	flood_fill(arr_map, col - 1, row, map_size);
	flood_fill(arr_map, col + 1, row, map_size);
	flood_fill(arr_map, col, row - 1, map_size);
	flood_fill(arr_map, col, row + 1, map_size);
}

static void	check_flooded(char **arr_map, t_coord *map_size)
{
	int	i;
	int	j;

	i = 0;
	while (i < map_size->col)
	{
		j = 0;
		while (j < map_size->row)
		{
			if (arr_map[i][j] == 'E' || arr_map[i][j] == 'C')
				ft_exit("no valid path\nError", STDERR_FILENO, EXIT_FAILURE);
			j++;
		}
		i++;
	}
}

void	validate_path(t_list *list_map)
{
	char	**arr_map;
	t_coord	map_size;
	t_coord	start_coord;

	arr_map = NULL;
	get_map_size(&map_size, list_map);
	copy_map_to_arr(&arr_map, list_map, &map_size);
	get_start_coord(&start_coord, arr_map, &map_size);
	flood_fill(arr_map, start_coord.col, start_coord.row, &map_size);
	//Fix!
	print_map(arr_map, &map_size);
	check_flooded(arr_map, &map_size);
	ft_free(arr_map);
}
