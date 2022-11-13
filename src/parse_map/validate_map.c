/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 21:35:18 by minseok2          #+#    #+#             */
/*   Updated: 2022/11/13 21:35:48 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	validate_map(t_list *list_map)
{
	validate_rectangular_shape(list_map);
	validate_components(list_map);
	validate_surrounding_wall(list_map);
	validate_path(list_map);
}
