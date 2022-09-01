/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldenise <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 20:23:54 by ldenise           #+#    #+#             */
/*   Updated: 2021/03/09 20:43:17 by ldenise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdlib.h>

int		check_all_lines(char **str, int size, int len)
{
	int i;

	i = 2;
	while (i < len + 1)
	{
		if (ft_line_len(str[i++]) != size)
			return (0);
	}
	return (1);
}

int		ft_str_line(char **str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_bin_map(t_map *map, t_parametr *param, char **str)
{
	int i;
	int j;

	i = 1;
	while (i <= map->row)
	{
		j = 0;
		while (j < map->col)
		{
			if (str[i][j] == param->obs)
				map->arr[i - 1][j] = 0;
			else if (str[i][j] == param->empty)
				map->arr[i - 1][j] = 1;
			else
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		ft_get_map(char **str, t_parametr *param, t_map *map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	map->row = param->line_count;
	if (str[1])
		map->col = ft_line_len(str[1]);
	else
		return (0);
	if (!check_all_lines(str, map->col, map->row))
		return (0);
	map->arr = (int**)malloc(sizeof(int*) * map->row);
	while (i < map->row)
		map->arr[i++] = (int*)malloc(sizeof(int) * map->col);
	i = 1;
	if (!ft_bin_map(map, param, str))
		return (0);
	return (1);
}

int		ft_line_len(char *str)
{
	int i;
	int len;

	i = 0;
	len = 0;
	if (str)
	{
		while (str[i++])
			len++;
	}
	return (len);
}
