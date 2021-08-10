/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 00:43:58 by echung            #+#    #+#             */
/*   Updated: 2021/08/09 21:30:30 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct s_param{
	int		x;
	int		y;
	char	str[3];
}	t_param;

# include "../mlx/mlx.h"
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
	t_param			param;
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
}	t_global;

typedef struct s_iter
{
	int	i;
	int	j;
	int	k;
	int	l;
	int	m;

}	t_iter;

int				key_press(int keycode);
void			param_init(t_param *param);
char	**readfile(char *filename, int row);
int		count_gnl(char *filename);
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

void	load_image(void);

void	init_map(t_iter it);
void	edit_map(int param_x, int param_y);

int	parse_map(char **arr, int row, int column);

#endif
