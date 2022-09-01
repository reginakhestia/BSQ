/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_fts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldenise <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:29:16 by ldenise           #+#    #+#             */
/*   Updated: 2021/03/09 13:08:27 by ldenise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft.h"

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i++])
	{
	}
	return (i);
}

char	*ft_strndup(char *src, int n)
{
	int		i;
	char	*dup_ptr;

	dup_ptr = (char*)malloc(sizeof(char) * (n + 1));
	if (dup_ptr == NULL)
		return (NULL);
	i = 0;
	while (src[i] && i < n)
	{
		dup_ptr[i] = src[i];
		i++;
	}
	dup_ptr[i] = '\0';
	return (dup_ptr);
}

int		ft_min(int a, int b, int c)
{
	int		min;

	min = a;
	if (b < min)
		min = b;
	if (c < min)
		min = c;
	return (min);
}

void	ft_init_max(t_side *max, int x, int y, int maxx)
{
	max->side = maxx;
	max->i = x;
	max->j = y;
}
