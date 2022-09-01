/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldenise <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:59:15 by ldenise           #+#    #+#             */
/*   Updated: 2021/03/10 19:05:41 by ldenise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int		main(int argc, char **argv)
{
	if (argc == 1)
		ft_one_solution();
	else
		more_than_one_map(argc, argv);
}

void	more_than_one_map(int argc, char **argv)
{
	char	*str;
	int		fd;
	int		i;

	i = 1;
	while (1)
	{
		str = NULL;
		if (!(fd = ft_get_fd(argv, i)))
			return ;
		read_file(fd, &str);
		if (!ft_n_error(str))
		{
			if (++i >= argc)
				return ;
			write(1, "\n", 1);
			continue ;
		}
		if (!find_solution(str))
			write(2, "map error\n", 10);
		if (++i >= argc)
			break ;
		write(1, "\n", 1);
		close(fd);
	}
}

void	ft_one_solution(void)
{
	char *str;

	read_file(0, &str);
	if (!ft_n_error(str))
		return ;
	if (!find_solution(str))
		write(2, "map error\n", 10);
}

int		ft_get_fd(char **argv, int i)
{
	int fd;

	fd = 0;
	if ((fd = open(argv[i], O_RDONLY)) < 0)
	{
		write(2, "map error\n", 10);
		return (0);
	}
	return (fd);
}

int		find_solution(char *str)
{
	char		**map;
	t_map		int_map;
	t_parametr	params;
	t_side		max_square;

	map = ft_split(str, "\n\v\f");
	if (*map)
	{
		if (!ft_first_line(map[0], &params))
			return (0);
	}
	else
		return (0);
	if (!ft_get_map(map, &params, &int_map))
		return (0);
	if (int_map.row == 1 || int_map.col == 1)
		ft_find_max_dot(&int_map, &max_square, &params);
	else if (!ft_find_max_sqr(&int_map, &max_square, &params))
		return (0);
	return (1);
}
