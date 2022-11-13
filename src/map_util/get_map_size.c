/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 21:46:21 by minseok2          #+#    #+#             */
/*   Updated: 2022/11/13 21:46:34 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	get_map_size(t_coord *map_size, t_list *list_map)
{
	t_node	*current_node;

	map_size->col = list_map->size;
	current_node = list_map->head->next;
	map_size->row = ft_strlen(current_node->line);
}
