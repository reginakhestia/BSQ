/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khestia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 16:58:04 by khestia           #+#    #+#             */
/*   Updated: 2021/03/09 21:13:19 by ldenise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <unistd.h>

char	ft_cmp_char(int n, t_parametr *p)
{
	if (n == 0)
		return (p->obs);
	if (n == 1)
		return (p->empty);
	if (n == -1)
		return (p->full);
	return (p->empty);
}

void	ft_print_map(t_map *map, int line_count, int line_size, t_parametr *p)
{
	int			x;
	int			y;
	char		c;

	x = 0;
	while (x < line_count)
	{
		y = 0;
		while (y < line_size)
		{
			c = ft_cmp_char(map->arr[x][y], p);
			write(1, &c, 1);
			y++;
		}
		write(1, "\n", 1);
		x++;
	}
}

void	ft_full_map(t_side *max, t_map *map, t_parametr *p)
{
	int		x;
	int		y;

	x = 0;
	while (x < map->row)
	{
		y = 0;
		while (y < map->col)
		{
			if ((x >= (max->i - (max->side - 1)) && x <= max->i) && (y >=
						(max->j - (max->side - 1)) && y <= max->j))
				map->arr[x][y] = -1;
			y++;
		}
		x++;
	}
	ft_print_map(map, map->row, map->col, p);
}
