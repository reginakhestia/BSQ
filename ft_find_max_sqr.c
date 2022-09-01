/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_max_sqr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldenise <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 20:58:43 by ldenise           #+#    #+#             */
/*   Updated: 2021/03/10 14:36:42 by ldenise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <unistd.h>

void	ft_max_find(t_map *map, t_side *max)
{
	int i;
	int j;

	i = 0;
	while (i < map->row)
	{
		j = 0;
		while (j < map->col)
		{
			if (map->arr[i][j] == max->side)
			{
				max->i = i;
				max->j = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

int		ft_find_max_sqr(t_map *map, t_side *max, t_parametr *p)
{
	int		x;
	int		y;

	max->side = 0;
	x = 1;
	y = 1;
	while (x < map->row)
	{
		y = 1;
		while (y < map->col)
		{
			if (map->arr[x][y] != 0)
				map->arr[x][y] = ft_min(map->arr[x - 1][y], map->arr[x][y - 1],
						map->arr[x - 1][y - 1]) + 1;
			if (map->arr[x][y] > max->side)
				ft_init_max(max, x, y, map->arr[x][y]);
			y++;
		}
		x++;
	}
	ft_max_find(map, max);
	ft_full_map(max, map, p);
	return (1);
}

void	max_dot_col(t_map *map, t_side *max)
{
	int		b;

	b = 0;
	while (b < map->col)
	{
		if (map->arr[0][b] == 1)
		{
			ft_init_max(max, 0, b, map->arr[0][b]);
			break ;
		}
		b++;
	}
}

void	max_dot_row(t_map *map, t_side *max)
{
	int a;

	a = 0;
	while (a < map->row)
	{
		if (map->arr[a][0] == 1)
		{
			ft_init_max(max, a, 0, map->arr[a][0]);
			break ;
		}
		a++;
	}
}

void	ft_find_max_dot(t_map *map, t_side *max, t_parametr *p)
{
	int		a;
	int		b;

	a = 0;
	b = 0;
	if (p->line_count == 1)
		max_dot_col(map, max);
	else if (map->col == 1)
		max_dot_row(map, max);
	ft_full_map(max, map, p);
}
