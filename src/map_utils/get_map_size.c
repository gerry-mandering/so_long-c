/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 23:03:27 by minseok2          #+#    #+#             */
/*   Updated: 2022/11/16 23:22:37 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_idx	get_map_size(t_list *map_lst)
{
	t_idx	map_size;
	t_node	*current_node;

	current_node = map_lst->head->next;
	map_size.row = map_lst->size;
	map_size.col = ft_strlen(current_node->line);
	return (map_size);
}
