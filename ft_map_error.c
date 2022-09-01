/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldenise <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 13:23:04 by ldenise           #+#    #+#             */
/*   Updated: 2021/03/10 15:01:23 by ldenise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <fcntl.h>
#include <unistd.h>

int		ft_find_error_size(char **map)
{
	int		line_size;
	int		i;
	int		j;

	j = 0;
	line_size = 0;
	while (map[1][j] != '\0')
	{
		line_size++;
		j++;
	}
	i = 1;
	while (map[i][j])
	{
		j = 0;
		while (map[i][j] != '\0')
			j++;
		if (j != line_size)
			return (0);
		i++;
	}
	return (1);
}
