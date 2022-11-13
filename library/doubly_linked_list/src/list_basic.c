/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_basic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 15:43:44 by minseok2          #+#    #+#             */
/*   Updated: 2022/11/13 16:07:23 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/doubly_linked_list.h"

int	is_empty(t_list *list)
{
	if ((list->size) == 0)
		return (1);
	else
		return (0);
}

char	*get_first(t_list *list)
{
	t_node	*first_node;

	if (is_empty(list))
		ft_exit("list is empty", STDERR_FILENO, EXIT_FAILURE);
	first_node = list->head->next;
	return (first_node->line);
}

char	*get_last(t_list *list)
{
	t_node	*last_node;

	if (is_empty(list))
		ft_exit("list is empty", STDERR_FILENO, EXIT_FAILURE);
	last_node = list->tail->prev;
	return (last_node->line);
}

void	init_list(t_list *list)
{
	list->head = (t_node *)ft_calloc(1, sizeof(t_node));
	list->tail = (t_node *)ft_calloc(1, sizeof(t_node));
	list->head->next = list->tail;
	list->tail->prev = list->head;
	list->size = 0;
}
