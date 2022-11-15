/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 15:14:20 by minseok2          #+#    #+#             */
/*   Updated: 2022/11/15 22:05:04 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_character_pack(t_assets *assets, void *mlx_ptr)
{
	assets->character.up[0] = mlx_xpm_file_to_image(mlx_ptr, \
	"../assets/character/up_0.xpm", &assets->width, &assets->height);
	assets->character.down[0] = mlx_xpm_file_to_image(mlx_ptr, \
	"../assets/character/down_0.xpm", &assets->width, &assets->height);
	assets->character.left[0] = mlx_xpm_file_to_image(mlx_ptr, \
	"../assets/character/left_0.xpm", &assets->width, &assets->height);
	assets->character.right[0] = mlx_xpm_file_to_image(mlx_ptr, \
	"../assets/character/right_0.xpm", &assets->width, &assets->height);
}

void	init_object_pack(t_assets *assets, void *mlx_ptr)
{
	assets->object.tree_top = mlx_xpm_file_to_image(mlx_ptr, \
	"../assets/map/object/tree_up.xpm", &assets->width, &assets->height);
	assets->object.tree_middle = mlx_xpm_file_to_image(mlx_ptr, \
	"../assets/map/object/tree_mid.xpm", &assets->width, &assets->height);
	assets->object.tree_bottom = mlx_xpm_file_to_image(mlx_ptr, \
	"../assets/map/object/tree_down.xpm", &assets->width, &assets->height);
	assets->object.others[IDX_SIGN] = mlx_xpm_file_to_image(mlx_ptr, \
	"../assets/map/object/sign.xpm", &assets->width, &assets->height);
	assets->object.others[IDX_FENCE] = mlx_xpm_file_to_image(mlx_ptr, \
	"../assets/map/object/fence.xpm", &assets->width, &assets->height);
	assets->object.others[IDX_BUSH] = mlx_xpm_file_to_image(mlx_ptr, \
	"../assets/map/object/bush.xpm", &assets->width, &assets->height);
	assets->object.others[IDX_ROCK] = mlx_xpm_file_to_image(mlx_ptr, \
	"../assets/map/object/rock.xpm", &assets->width, &assets->height);
}

void	init_wall_pack(t_assets *assets, void *mlx_ptr)
{
	assets->wall.up_left = mlx_xpm_file_to_image(mlx_ptr, \
	"../assets/map/surrounding_wall/up_left.xpm", \
	&assets->width, &assets->height);
	assets->wall.up_center = mlx_xpm_file_to_image(mlx_ptr, \
	"../assets/map/surrounding_wall/up_center.xpm", \
	&assets->width, &assets->height);
	assets->wall.up_right = mlx_xpm_file_to_image(mlx_ptr, \
	"../assets/map/surrounding_wall/up_right.xpm", \
	&assets->width, &assets->height);
	assets->wall.mid_left = mlx_xpm_file_to_image(mlx_ptr, \
	"../assets/map/surrounding_wall/mid_left.xpm", \
	&assets->width, &assets->height);
	assets->wall.mid_right = mlx_xpm_file_to_image(mlx_ptr, \
	"../assets/map/surrounding_wall/mid_right.xpm", \
	&assets->width, &assets->height);
	assets->wall.down_left = mlx_xpm_file_to_image(mlx_ptr, \
	"../assets/map/surrounding_wall/down_left.xpm", \
	&assets->width, &assets->height);
	assets->wall.down_center = mlx_xpm_file_to_image(mlx_ptr, \
	"../assets/map/surrounding_wall/down_center.xpm", \
	&assets->width, &assets->height);
	assets->wall.down_right = mlx_xpm_file_to_image(mlx_ptr, \
	"../assets/map/surrounding_wall/down_right.xpm", \
	&assets->width, &assets->height);
}

void	init_assets(t_assets *assets, void *mlx_ptr)
{
	assets->tile = mlx_xpm_file_to_image(mlx_ptr, \
	"../assets/map/tile/snow.xpm", &assets->width, &assets->height);
	assets->collectible = mlx_xpm_file_to_image(mlx_ptr, \
	"../assets/collectible/box.xpm", &assets->width, &assets->height);
	assets->exit = mlx_xpm_file_to_image(mlx_ptr, \
	"../assets/map/exit/exit.xpm", &assets->width, &assets->height);
	init_character_pack(assets, mlx_ptr);
	init_object_pack(assets, mlx_ptr);
	init_wall_pack(assets, mlx_ptr);
}

void	labeling_corner_wall(t_pack *pack)
{
	char	**arr_map;
	t_coord	*map_size;

	arr_map = pack->arr_map;
	map_size = &pack->map_size;
	arr_map[0][0] = UP_LEFT;
	arr_map[0][map_size->row - 1] = UP_RIGHT;
	arr_map[map_size->col - 1][0] = DOWN_LEFT;
	arr_map[map_size->col - 1][map_size->row - 1] = DOWN_RIGHT;
}

void	labeling_side_wall(t_pack *pack)
{
	int		i;
	char	**arr_map;
	t_coord	*map_size;

	i = 1;
	arr_map = pack->arr_map;
	map_size = &pack->map_size;
	while (i < map_size->col - 1)
	{
		arr_map[i][0] = LEFT_SIDE;
		arr_map[i][map_size->row - 1] = RIGHT_SIDE;
		i++;
	}
	i = 1;
	while (i < map_size->row - 1)
	{
		arr_map[0][i] = UP_SIDE;
		arr_map[map_size->col - 1][i] = DOWN_SIDE;
		i++;
	}
}

void	labeling_surrounding_wall(t_pack *pack)
{
	labeling_corner_wall(pack);
	labeling_side_wall(pack);
}

int	count_continuous_wall(t_pack *pack, t_index index)
{
	char	**arr_map;
	t_coord	*map_size;
	int		count;

	arr_map = pack->arr_map;
	map_size = &pack->map_size;
	count = 0;
	while (index.i < map_size->col - 2)
	{
		if (arr_map[index.i][index.j] == '1')
			count++;
		else
			break ;
		index.i++;
	}
	return (count);
}

void	labeling_single_tree(t_pack *pack, t_index index)
{
	char	**arr_map;
	t_coord	*map_size;

	arr_map = pack->arr_map;
	map_size = &pack->map_size;
	arr_map[index.i][index.j] = TREE_UP;
	arr_map[index.i + 1][index.j] = TREE_DOWN;
}

void	labeling_double_tree(t_pack *pack, t_index index)
{
	char	**arr_map;
	t_coord	*map_size;

	arr_map = pack->arr_map;
	map_size = &pack->map_size;
	arr_map[index.i][index.j] = TREE_UP;
	arr_map[index.i + 1][index.j] = TREE_MID;
	arr_map[index.i + 2][index.j] = TREE_DOWN;
}

void	labeling_tree(t_pack *pack)
{
	t_index	index;
	char	**arr_map;
	t_coord	*map_size;

	index.i = 1;
	arr_map = pack->arr_map;
	map_size = &pack->map_size;
	while (index.i < map_size->col - 2)
	{
		index.j = 0;
		while (index.j < map_size->row - 1)
		{
			if (count_continuous_wall(pack, index) == 2)
				labeling_single_tree(pack, index);
			else if (count_continuous_wall(pack, index) >= 3)
				labeling_double_tree(pack, index);
			index.j++;
		}
		index.i++;
	}
}

char	get_objects_in_order(void)
{
	static int	count;
	const char	arr_objects[4] = {'s', 'd', 'x', 'c'};

	return (arr_objects[count++ % 4]);
}

void	labeling_object(t_pack *pack)
{
	t_index	index;
	char	**arr_map;
	t_coord	*map_size;

	index.i = 1;
	arr_map = pack->arr_map;
	map_size = &pack->map_size;
	while (index.i < map_size->col - 2)
	{
		index.j = 0;
		while (index.j < map_size->row - 1)
		{
			if (arr_map[index.i][index.j] == '1')
				arr_map[index.i][index.j] = get_objects_in_order();
			index.j++;
		}
		index.i++;
	}
}

void	labeling_map(t_pack *pack)
{
	labeling_surrounding_wall(pack);
	labeling_tree(pack);
	labeling_object(pack);
}

void	init_mlx_and_window(t_pack *pack)
{
	pack->ptr.mlx = mlx_init();
	pack->ptr.win = mlx_new_window(pack->ptr.mlx, \
	(pack->map_size.row * 32), (pack->map_size.col * 32), "Merry Christmas");
}

void	init_pack(t_pack *pack, t_list *list_map)
{
	get_map_size(&(pack->map_size), list_map);
	copy_map_to_arr(&(pack->arr_map), list_map, &(pack->map_size));
	labeling_map(pack);
	init_mlx_and_window(pack);
	init_assets(&(pack->assets), pack->ptr.mlx);
}

int	main(int argc, char **argv)
{
	t_list		list_map;
	t_pack		pack;

	parse_map(&list_map, argc, argv);
	init_pack(&pack, &list_map);
	init_first_monitor();
	mlx_loop(pack.ptr.mlx);
	return (0);
}
