/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 00:43:58 by echung            #+#    #+#             */
/*   Updated: 2021/08/10 18:42:23 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct s_param{
	int		x;
	int		y;
	char	str[3];
}	t_param;

typedef struct s_iter
{
	int	i;
	int	j;
	int	k;
	int	l;
	int	m;

}	t_iter;
# include "../srcs/mlx/mlx.h"
# include "so_long.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_RELEASE 3
# define X_EVENT_KEY_EXIT 17 // exit key code

// Mac key code example
# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

// x,y and str are meaningless variables.

typedef struct s_global{
	void			*mlx;
	void			*win;
	void			*img_w1;
	void			*img_w3;
	void			*back;
	void			*tree;
	void			*portal;
	void			*heart_r;
	int				heart;
	char			**arr;
	int				start_x;
	int				start_y;
	int				row;
	int				column;
	int				collectibles;
	t_param			param;
	t_iter			iter;
}	t_global;


int				key_press(int keycode, t_global *g);
void			param_init(t_global *g);
char	**readfile(char *filename, int row);
int		count_row(char *filename);
int			get_next_line(int fd, char **line);
//static int	save_line(char **str, char **line, int index);
//int	find_index(char *s, char c);
char	*ft_strdup(char *src);
char	*ft_strjoin_free(char *s1, char *s2);
char	*ft_strjoin_free_sub(char *str, char *buff);
char	*ft_substr(char *s, int start, int len);
int	ft_strlen(char *str);

void	*ft_memset(void *b, int c, int len);
void	ft_bzero(void *s, int n);
void	*ft_memcpy(void *dst, void *src, int n);

int	parse_map(char **arr, int row, int column);
int	is_instring(int c, char *s);

void	load_image(t_global *g);

void	init_map(t_global *g);
void	edit_map(t_global *g);

int	parse_map(char **arr, int row, int column);

void	img_to_win(t_global *g, void *img, int i, int j);

#endif