/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 15:58:41 by minseok2          #+#    #+#             */
/*   Updated: 2022/11/14 10:34:20 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	validate_file_name(char *file_name)
{
	int	len;
	int	extension_len;

	len = ft_strlen(file_name);
	extension_len = 4;
	if (ft_memcmp(file_name + (len - extension_len), ".ber", 4) != 0)
		ft_exit("wrong file name\nError", STDERR_FILENO, EXIT_FAILURE);
}

static void	remove_new_line(char *line)
{
	int	len;

	len = ft_strlen(line);
	if (line[len - 1] == '\n')
		line[len - 1] = '\0';
}

void	parse_map(t_list *list_map, int argc, char **argv)
{
	int		fd;
	t_node	*current_node;
	char	*line;

	if (argc != 2)
		ft_exit("wrong arguments count\nError", STDERR_FILENO, EXIT_FAILURE);
	validate_file_name(argv[1]);
	fd = ft_open(argv[1], O_RDONLY);
	current_node = list_map->head->next;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		remove_new_line(line);
		push_tail_side(list_map, new_node(line));
	}
	validate_map(list_map);
	ft_close(fd);
}
