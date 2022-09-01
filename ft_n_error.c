/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_n_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khestia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 18:40:11 by khestia           #+#    #+#             */
/*   Updated: 2021/03/10 18:56:23 by khestia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft.h"

int		ft_n_error(char *str)
{
	int		i;

	i = 0;
	if (!str)
	{
		write(2, "map error\n", 10);
		return (0);
	}
	if (str[0] == '\n' || str[0] == '\v' || str[0] == '\f')
	{
		write(2, "map error\n", 10);
		return (0);
	}
	while (str[i + 1])
	{
		if ((str[i] == '\n' || str[i] == '\v' || str[i] == '\f') &&
				(str[i + 1] == '\n' || str[i + 1] == '\v'
				|| str[i + 1] == '\f'))
		{
			write(2, "map error\n", 10);
			return (0);
		}
		i++;
	}
	return (1);
}
