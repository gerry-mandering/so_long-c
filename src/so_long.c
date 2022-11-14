/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 15:14:20 by minseok2          #+#    #+#             */
/*   Updated: 2022/11/14 20:17:49 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_character_pack(t_img_pack *img_pack, void *mlx_ptr)
{
	img_pack->character.up[0] = mlx_xpm_file_to_image(mlx_ptr, \
	"../assets/character/up_0.xpm", &img_pack->width, &img_pack->height);
	img_pack->character.up[1] = mlx_xpm_file_to_image(mlx_ptr, \
	"../assets/character/up_1.xpm", &img_pack->width, &img_pack->height);
	img_pack->character.up[2] = mlx_xpm_file_to_image(mlx_ptr, \
	"../assets/character/up_2.xpm", &img_pack->width, &img_pack->height);
	img_pack->character.down[0] = mlx_xpm_file_to_image(mlx_ptr, \
	"../assets/character/down_0.xpm", &img_pack->width, &img_pack->height);
	img_pack->character.down[1] = mlx_xpm_file_to_image(mlx_ptr, \
	"../assets/character/down_1.xpm", &img_pack->width, &img_pack->height);
	img_pack->character.down[2] = mlx_xpm_file_to_image(mlx_ptr, \
	"../assets/character/down_2.xpm", &img_pack->width, &img_pack->height);
	img_pack->character.left[0] = mlx_xpm_file_to_image(mlx_ptr, \
	"../assets/character/left_0.xpm", &img_pack->width, &img_pack->height);
	img_pack->character.left[1] = mlx_xpm_file_to_image(mlx_ptr, \
	"../assets/character/left_1.xpm", &img_pack->width, &img_pack->height);
	img_pack->character.left[2] = mlx_xpm_file_to_image(mlx_ptr, \
	"../assets/character/left_2.xpm", &img_pack->width, &img_pack->height);
	img_pack->character.right[0] = mlx_xpm_file_to_image(mlx_ptr, \
	"../assets/character/right_0.xpm", &img_pack->width, &img_pack->height);
	img_pack->character.right[1] = mlx_xpm_file_to_image(mlx_ptr, \
	"../assets/character/right_1.xpm", &img_pack->width, &img_pack->height);
	img_pack->character.right[2] = mlx_xpm_file_to_image(mlx_ptr, \
	"../assets/character/right_2.xpm", &img_pack->width, &img_pack->height);
}

void	init_object_pack(t_img_pack *img_pack, void *mlx_ptr)
{
	img_pack->object.tree_top = mlx_xpm_file_to_image(mlx_ptr, \
	"../assets/map/object/tree_up.xpm", &img_pack->width, &img_pack->height);
	img_pack->object.tree_middle = mlx_xpm_file_to_image(mlx_ptr, \
	"../assets/map/object/tree_mid.xpm", &img_pack->width, &img_pack->height);
	img_pack->object.tree_bottom = mlx_xpm_file_to_image(mlx_ptr, \
	"../assets/map/object/tree_down.xpm", &img_pack->width, &img_pack->height);
	img_pack->object.others[SIGN] = mlx_xpm_file_to_image(mlx_ptr, \
	"../assets/map/object/sign.xpm", &img_pack->width, &img_pack->height);
	img_pack->object.others[FENCE] = mlx_xpm_file_to_image(mlx_ptr, \
	"../assets/map/object/fence.xpm", &img_pack->width, &img_pack->height);
	img_pack->object.others[BUSH] = mlx_xpm_file_to_image(mlx_ptr, \
	"../assets/map/object/bush.xpm", &img_pack->width, &img_pack->height);
	img_pack->object.others[ROCK] = mlx_xpm_file_to_image(mlx_ptr, \
	"../assets/map/object/rock.xpm", &img_pack->width, &img_pack->height);
}

void	init_wall_pack(t_img_pack *img_pack, void *mlx_ptr)
{
	img_pack->wall.up_left = mlx_xpm_file_to_image(mlx_ptr, \
	"../assets/map/surrounding_wall/up_left.xpm", \
	&img_pack->width, &img_pack->height);
	img_pack->wall.up_center = mlx_xpm_file_to_image(mlx_ptr, \
	"../assets/map/surrounding_wall/up_center.xpm", \
	&img_pack->width, &img_pack->height);
	img_pack->wall.up_right = mlx_xpm_file_to_image(mlx_ptr, \
	"../assets/map/surrounding_wall/up_right.xpm", \
	&img_pack->width, &img_pack->height);
	img_pack->wall.mid_left = mlx_xpm_file_to_image(mlx_ptr, \
	"../assets/map/surrounding_wall/mid_left.xpm", \
	&img_pack->width, &img_pack->height);
	img_pack->wall.mid_right = mlx_xpm_file_to_image(mlx_ptr, \
	"../assets/map/surrounding_wall/mid_right.xpm", \
	&img_pack->width, &img_pack->height);
	img_pack->wall.down_left = mlx_xpm_file_to_image(mlx_ptr, \
	"../assets/map/surrounding_wall/down_left.xpm", \
	&img_pack->width, &img_pack->height);
	img_pack->wall.down_center = mlx_xpm_file_to_image(mlx_ptr, \
	"../assets/map/surrounding_wall/down_center.xpm", \
	&img_pack->width, &img_pack->height);
	img_pack->wall.down_right = mlx_xpm_file_to_image(mlx_ptr, \
	"../assets/map/surrounding_wall/down_right.xpm", \
	&img_pack->width, &img_pack->height);
}

void	init_img_pack(t_img_pack *img_pack, void *mlx_ptr)
{
	img_pack->tile = mlx_xpm_file_to_image(mlx_ptr, \
	"../assets/map/tile/snow.xpm", &img_pack->width, &img_pack->height);
	img_pack->collectible = mlx_xpm_file_to_image(mlx_ptr, \
	"../assets/collectible/box.xpm", &img_pack->width, &img_pack->height);
	img_pack->exit = mlx_xpm_file_to_image(mlx_ptr, \
	"../assets/map/exit/exit.xpm", &img_pack->width, &img_pack->height);
	init_character_pack(img_pack, mlx_ptr);
	init_object_pack(img_pack, mlx_ptr);
	init_wall_pack(img_pack, mlx_ptr);
}

void	init_corner_wall(t_ptr *ptr, t_img_pack *img_pack, t_index *index, t_coord *map_size)
{
	if (index->i == 0 && index->j == 0)
		mlx_put_image_to_window(ptr->mlx, ptr->win, img_pack->wall.up_left, index->j * 32, index->i * 32);
	else if (index->i == 0 && index->j == (map_size->row - 1))
		mlx_put_image_to_window(ptr->mlx, ptr->win, img_pack->wall.up_right, index->j * 32, index->i * 32);
	else if (index->i == (map_size->col - 1) && index->j == 0)
		mlx_put_image_to_window(ptr->mlx, ptr->win, img_pack->wall.down_left, index->j * 32, index->i * 32);
	else if (index->i == (map_size->col - 1) && index->j == (map_size->row - 1))
		mlx_put_image_to_window(ptr->mlx, ptr->win, img_pack->wall.down_right, index->j * 32, index->i * 32);
}

void	init_wall(t_ptr *ptr, t_img_pack *img_pack, t_coord *map_size)
{
	t_index	index;

	index.i = 0;
	while (index.i < map_size->col)
	{
		index.j = 0;
		while (index.j < map_size->row)
		{
			if ((index.i == 0 && index.j == 0) || \
				(index.i == 0 && index.j == (map_size->row - 1)) || \
				(index.i == (map_size->col - 1) && index.j == 0) || \
				(index.i == (map_size->col - 1) && index.j == (map_size->row - 1)))
				init_corner_wall(ptr, img_pack, &index, map_size);
			else if (index.i == 0)
				mlx_put_image_to_window(ptr->mlx, ptr->win, img_pack->wall.up_center, index.j * 32, index.i * 32);
			else if (index.i == (map_size->col - 1))
				mlx_put_image_to_window(ptr->mlx, ptr->win, img_pack->wall.down_center, index.j * 32, index.i * 32);
			else if (index.j == 0)
				mlx_put_image_to_window(ptr->mlx, ptr->win, img_pack->wall.mid_left, index.j * 32, index.i * 32);
			else if (index.j == (map_size->row - 1))
				mlx_put_image_to_window(ptr->mlx, ptr->win, img_pack->wall.mid_right, index.j * 32, index.i * 32);
			else
				mlx_put_image_to_window(ptr->mlx, ptr->win, img_pack->tile, index.j * 32, index.i * 32);
			index.j++;
		}
		index.i++;
	}
}

void	init_character(t_ptr *ptr, t_img_pack *img_pack, char **arr_map, t_coord *map_size)
{
	t_index	index;

	index.i = 0;
	while (index.i < map_size->col)
	{
		index.j = 0;
		while (index.j < map_size->row)
		{
			if (arr_map[index.i][index.j] == 'P')
				mlx_put_image_to_window(ptr->mlx, ptr->win, img_pack->character.down[1], index.j * 32, index.i * 32);
			index.j++;
		}
		index.i++;
	}
}

int	count_continuous_wall(char **arr_map, t_coord *map_size, t_index index)
{
	int	continous_wall;

	continous_wall = 0;
	while (index.i < (map_size->col - 2))
	{
		if (arr_map[index.i][index.j] == '1')
			continous_wall++;
		else
			break;
		(index.i)++;
	}
	return (continous_wall);
}

void	init_single_tree(t_ptr *ptr, t_img_pack *img_pack, char **arr_map, t_index index)
{
	int	i;
	int	size;

	i = 0;
	size = 2;
	while (i < size)
	{
		if (i == 0)
			mlx_put_image_to_window(ptr->mlx, ptr->win, img_pack->object.tree_top, index.j * 32, index.i * 32);
		else if (i == 1)
			mlx_put_image_to_window(ptr->mlx, ptr->win, img_pack->object.tree_bottom, index.j * 32, index.i * 32);
		arr_map[(index.i)++][index.j] = 't';
		i++;
	}
}

void	init_double_tree(t_ptr *ptr, t_img_pack *img_pack, char **arr_map, t_index index)
{
	int	i;
	int	size;

	i = 0;
	size = 3;
	while (i < size)
	{
		if (i == 0)
			mlx_put_image_to_window(ptr->mlx, ptr->win, img_pack->object.tree_top, index.j * 32, index.i * 32);
		else if (i == 1)
			mlx_put_image_to_window(ptr->mlx, ptr->win, img_pack->object.tree_middle, index.j * 32, index.i * 32);
		else if (i == 2)
			mlx_put_image_to_window(ptr->mlx, ptr->win, img_pack->object.tree_bottom, index.j * 32, index.i * 32);
		arr_map[(index.i)++][index.j] = 't';
		i++;
	}
}

void	init_tree(t_ptr *ptr, t_img_pack *img_pack, char **arr_map, t_coord *map_size)
{
	t_index	index;
	int		continous_wall;

	index.i = 1;
	while (index.i < (map_size->col - 2))
	{
		index.j = 1;
		while (index.j < (map_size->row - 1))
		{
			continous_wall = count_continuous_wall(arr_map, map_size, index);
			if (continous_wall == 2)
				init_single_tree(ptr, img_pack, arr_map, index);
			else if (continous_wall >= 3)
				init_double_tree(ptr, img_pack, arr_map, index);
			index.j++;
		}
		index.i++;
	}
}

void	init_object(t_ptr *ptr, t_img_pack *img_pack, char **arr_map, t_coord *map_size)
{
	t_index	index;
	int		object_count;

	index.i = 1;
	object_count = 0;
	while (index.i < map_size->col - 1)
	{
		index.j = 1;
		while (index.j < map_size->row - 1)
		{
			if (arr_map[index.i][index.j] == '1')
			{
				mlx_put_image_to_window(ptr->mlx, ptr->win, img_pack->object.others[object_count % 4], index.j * 32, index.i * 32);
				object_count++;
			}
			index.j++;
		}
		index.i++;
	}
}

void	init_collectible(t_ptr *ptr, t_img_pack *img_pack, char **arr_map, t_coord *map_size)
{
	t_index	index;

	index.i = 1;
	while (index.i < map_size->col - 1)
	{
		index.j = 1;
		while (index.j < map_size->row - 1)
		{
			if (arr_map[index.i][index.j] == 'C')
				mlx_put_image_to_window(ptr->mlx, ptr->win, img_pack->collectible, index.j * 32, index.i * 32);
			index.j++;
		}
		index.i++;
	}
}

void	init_exit(t_ptr *ptr, t_img_pack *img_pack, char **arr_map, t_coord *map_size)
{
	t_index	index;

	index.i = 0;
	while (index.i < map_size->col)
	{
		index.j = 0;
		while (index.j < map_size->row)
		{
			if (arr_map[index.i][index.j] == 'E')
				mlx_put_image_to_window(ptr->mlx, ptr->win, img_pack->exit, index.j * 32, index.i * 32);
			index.j++;
		}
		index.i++;
	}
}

void	init_window_img(t_ptr *ptr, t_img_pack *img_pack, t_list *list_map)
{
	t_coord	map_size;
	char	**arr_map;

	get_map_size(&map_size, list_map);
	copy_map_to_arr(&arr_map, list_map, &map_size);
	init_wall(ptr, img_pack, &map_size);
	init_character(ptr, img_pack, arr_map, &map_size);
	init_tree(ptr, img_pack, arr_map, &map_size);
	init_object(ptr, img_pack, arr_map, &map_size);
	init_collectible(ptr, img_pack, arr_map, &map_size);
	init_exit(ptr, img_pack, arr_map, &map_size);
	ft_free(arr_map);
}

int	main(int argc, char **argv)
{
	t_list		list_map;
	t_coord		map_size;
	t_ptr		ptr;
	t_img_pack	img_pack;

	init_list(&list_map);
	parse_map(&list_map, argc, argv);
	get_map_size(&map_size, &list_map);
	ft_printf("%d %d \n", map_size.col, map_size.row);
	ptr.mlx = mlx_init();
	ptr.win = mlx_new_window(ptr.mlx, \
			(map_size.row * 32), (map_size.col * 32), "Merry Christmas");
	init_img_pack(&img_pack, ptr.mlx);
	init_window_img(&ptr, &img_pack, &list_map);
	mlx_loop(ptr.mlx);
	return (0);
}
