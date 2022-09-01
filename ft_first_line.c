/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khestia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 12:35:40 by khestia           #+#    #+#             */
/*   Updated: 2021/03/09 20:26:38 by ldenise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <unistd.h>

int				ft_line_count(char *line, int count)
{
	int			nb;
	int			i;

	nb = 0;
	i = 0;
	while (i != count - 3)
	{
		if (line[i] >= '0' && line[i] <= '9' && line[0] != '0')
			nb = nb * 10 + (line[i] - '0');
		else
			return (0);
		i++;
	}
	return (nb);
}

void			ft_make_struct(char obs, char empt,
		char full, t_parametr *p)
{
	p->obs = obs;
	p->empty = empt;
	p->full = full;
}

int				ft_first_line(char *line, t_parametr *params)
{
	int			count;

	count = 0;
	while (line[count] != '\0')
	{
		if ((line[count] >= 0 && line[count] <= 32) || line[count] == 127)
			return (0);
		count++;
	}
	if (count < 4)
		return (0);
	else if (line[count - 2] == line[count - 3] ||
			line[count - 2] == line[count - 1] ||
			line[count - 1] == line[count - 3])
		return (0);
	else if (ft_line_count(line, count) != 0)
	{
		params->line_count = ft_line_count(line, count);
		ft_make_struct(line[count - 2], line[count - 3],
				line[count - 1], params);
		return (1);
	}
	else
		return (0);
}
