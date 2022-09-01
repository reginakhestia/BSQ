/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldenise <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 19:16:26 by ldenise           #+#    #+#             */
/*   Updated: 2021/03/09 21:12:10 by ldenise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int		read_file(int fd, char **file_ptr)
{
	char	buf[BUF_SIZE];
	int		file_size;
	int		read_size;

	file_size = 0;
	while ((read_size = read(fd, buf, BUF_SIZE)))
	{
		if (read_size < 0)
			return (-1);
		*file_ptr = ft_memcat(*file_ptr, buf, file_size, read_size);
		file_size += read_size;
	}
	return (file_size);
}

char	*ft_memcat(char *file, char buf[BUF_SIZE], int file_size,
					int buf_size)
{
	int		i;
	char	*file_copy;

	if ((file_copy = malloc(sizeof(char) * (file_size + 1))) == NULL)
		return (NULL);
	i = -1;
	while (++i < file_size)
		file_copy[i] = file[i];
	free(file);
	if ((file = malloc(sizeof(char) * (file_size + buf_size + 1))) == NULL)
		return (NULL);
	i = 0;
	while (i < file_size)
	{
		file[i] = file_copy[i];
		i++;
	}
	free(file_copy);
	while (i < file_size + buf_size)
	{
		file[i] = buf[i - file_size];
		i++;
	}
	return (file);
}
