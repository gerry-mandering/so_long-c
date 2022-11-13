/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 15:45:20 by minseok2          #+#    #+#             */
/*   Updated: 2022/11/13 16:17:52 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/doubly_linked_list.h"

void	clear_list(t_list *list)
{
	t_node	*current_node;
	t_node	*next_node;

	current_node = list->head->next;
	while (current_node->next != NULL)
	{
		next_node = current_node->next;
		ft_free(current_node->line);
		ft_free(current_node);
		current_node = next_node;
	}
	ft_free(list->head);
	ft_free(list->tail);
}
