/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 15:14:39 by minseok2          #+#    #+#             */
/*   Updated: 2022/11/14 20:14:48 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../library/libft/includes/libft.h"
# include "../library/ft_printf/includes/ft_printf.h"
# include "../library/get_next_line/includes/get_next_line.h"
# include "../library/mlx/mlx.h"
# include "../library/doubly_linked_list/includes/doubly_linked_list.h"

# define NOT_EXIST	0
# define EXIST		1

# define SIGN		0
# define FENCE		1
# define BUSH		2
# define ROCK		3

typedef struct s_ptr
{
	void	*mlx;
	void	*win;
}	t_ptr;

typedef struct s_index
{
	int	i;
	int	j;
}	t_index;

typedef struct s_components
{
	int	wall;
	int	collectibles;
	int	exit;
	int	starting_position;
}	t_components;

typedef struct s_coord
{
	int	col;
	int	row;
}	t_coord;

struct s_character_pack
{
	void	*up[3];
	void	*down[3];
	void	*left[3];
	void	*right[3];
};

struct s_wall_pack
{
	void	*up_left;
	void	*up_center;
	void	*up_right;
	void	*mid_left;
	void	*mid_right;
	void	*down_left;
	void	*down_center;
	void	*down_right;
};

struct s_object_pack
{
	void	*tree_top;
	void	*tree_middle;
	void	*tree_bottom;
	void	*others[4];
};

typedef struct s_img_pack
{
	struct s_wall_pack		wall;
	void					*tile;
	struct s_character_pack	character;
	struct s_object_pack	object;
	void					*collectible;
	void					*exit;
	int						width;
	int						height;
}	t_img_pack;

// map_util
void	copy_map_to_arr(char ***arr_map, t_list *list_map, t_coord *map_size);
void	move_map_to_arr(char ***arr_map, t_list *list_map, t_coord *map_size);
void	get_map_size(t_coord *map_size, t_list *list_map);
//FIX!!!
void	print_map(char **arr_map, t_coord *map_size);

// parse_map
void	parse_map(t_list *list_map, int argc, char **argv);
void	validate_map(t_list *list_map);
void	validate_rectangular_shape(t_list *list_map);
void	validate_components(t_list *list_map);
void	validate_surrounding_wall(t_list *list_map);
void	validate_path(t_list *list_map);

#endif
