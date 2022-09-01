# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldenise <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/08 14:37:41 by ldenise           #+#    #+#              #
#    Updated: 2021/03/10 21:56:40 by ldenise          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= main.c helper_fts.c ft_file_read.c ft_split.c ft_find_max_sqr.c ft_print_map.c ft_first_line.c ft_get_map.c ft_n_error.c

OBJS			= ${SRCS:.c=.o}

NAME			= bsq

GCC				= gcc

CFLAGS			= -Wall -Wextra -Werror

.c.o:			
				${GCC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:		${OBJS}
				${GCC} ${CFLAGS} ${OBJS} -o ${NAME}

all:			${NAME}

clean:			
				rm -f ${OBJS}

fclean:			clean
				rm -f ${NAME}

re:				fclean all

.SILENT:
