/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldenise <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:28:01 by ldenise           #+#    #+#             */
/*   Updated: 2021/03/10 19:02:48 by ldenise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H
# define BUF_SIZE 1024

typedef struct	s_parametr
{
	int		line_count;
	char	obs;
	char	full;
	char	empty;
}				t_parametr;

typedef struct	s_side
{
	int		i;
	int		j;
	int		side;
}				t_side;

typedef struct	s_map
{
	int	**arr;
	int col;
	int row;
}				t_map;

void			ft_putstr(char *str);
char			*ft_strcat(char *dest, char *src);
int				read_file(int fd, char **file_ptr);
char			*ft_memcat(char *file, char buf[BUF_SIZE], int file_size,
					int buf_size);
char			*ft_strndup(char *src, int n);
char			**ft_split(char *str, char *charset);
int				ft_find_max_sqr(t_map *map, t_side *max, t_parametr *p);
void			ft_full_map(t_side *max, t_map *map, t_parametr *p);
int				ft_first_line(char *line, t_parametr *params);
int				ft_get_map(char **str, t_parametr *param, t_map *map);
int				ft_line_len(char *str);
int				find_solution(char *str);
int				ft_find_error_chars(char **map, t_parametr *p);
void			ft_find_max_dot(t_map *map, t_side *max, t_parametr *p);
int				ft_n_error(char *str);
int				ft_min(int a, int b, int c);
void			ft_init_max(t_side *max, int x, int y, int maxx);
int				ft_get_fd(char **argv, int i);
void			ft_one_solution();
void			more_than_one_map(int argc, char **argv);

#endif
