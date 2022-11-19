/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 22:42:21 by minseok2          #+#    #+#             */
/*   Updated: 2022/11/18 19:37:28 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	validate_file_name(char *filename)
{
	const int	extension_len = 4;
	int			total_len;

	total_len = ft_strlen(filename);
	if (ft_memcmp(&filename[total_len - extension_len], ".ber", 4) != 0)
		ft_exit("Error\nwrong file name", STDERR_FILENO, EXIT_FAILURE);
}

static void	remove_newline(char *line)
{
	int	len;

	len = ft_strlen(line);
	if (len != 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
}

void	parse_map(t_list *map_lst, int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc != 2)
		ft_exit("Error\nwrong arguments count", STDERR_FILENO, EXIT_FAILURE);
	validate_file_name(argv[1]);
	fd = ft_open(argv[1], O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		remove_newline(line);
		push_tail_side(map_lst, new_node(line));
	}
	if (map_lst->size == 0)
		ft_exit("Error\nfile is empty", STDERR_FILENO, EXIT_FAILURE);
	validate_map(map_lst);
	ft_close(fd);
}
