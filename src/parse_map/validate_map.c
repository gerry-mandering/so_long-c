/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 22:59:26 by minseok2          #+#    #+#             */
/*   Updated: 2022/11/18 14:31:45 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	validate_map(t_list *map_lst)
{
	char		**map;
	const t_idx	map_size = get_map_size(map_lst);

	validate_rectangular_shape(map_lst, map_size);
	map = copy_map_to_char_array(map_lst, map_size);
	validate_components(map, map_size);
	validate_surrounding_wall(map, map_size);
	validate_path(map, map_size);
	free_char_map(map, map_size);
}
