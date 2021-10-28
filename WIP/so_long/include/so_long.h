/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 00:43:58 by echung            #+#    #+#             */
/*   Updated: 2021/10/28 14:27:24 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "so_long.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_RELEASE 3
# define X_EVENT_KEY_EXIT 17

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

# define STEP 48

typedef struct s_param{
	int		x;
	int		y;
}	t_param;

typedef struct s_iter
{
	int	i;
	int	j;
	int	k;
	int	l;
	int	m;

}	t_iter;

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
	int				item;
	int				start_x;
	int				start_y;
	char			**arr;
	int				row;
	int				column;
	int				movement;
	t_param			param;
	t_iter			iter;
}	t_global;

/*		srcs/key		*/
int		key_press(int keycode, t_global *g);
int		mouse_press(t_global *g);

/*		srcs/game		*/
int		init_game(char *map, t_global *g);
void	end_game(t_global *g);

/*		srcs/map		*/
int		is_valid_file_type(char *arg, char *type);
void	load_image(t_global *g);
/* map.c */
void	init_map(t_global *g);
void	edit_map(t_global *g);
/* parse_map.c */
int		is_valid_map(t_global *g);
/* readfile.c */
char	**read_map(char *map, int row);
int		count_row(char *map);

/*		utils			*/
/* get_next_line.c */
int		get_next_line(int fd, char **line);
/* lib.c */
void	*ft_memset(void *b, int c, int len);
void	ft_bzero(void *s, int n);
void	*ft_memcpy(void *dst, void *src, int n);
int		is_instring(int c, char *s);
int		check_char(char c1, char c2);
/* libstr.c */
char	*ft_strdup(char *src);
char	*ft_strjoin_free(char *s1, char *s2);
char	*ft_strjoin_free_sub(char *str, char *buff);
char	*ft_substr(char *s, int start, int len);
int		ft_strlen(char *str);
/* libfree.c */
void	free_all(char **s, int count);
/* short_mlx.c */
void	img_to_win(t_global *g, void *img, int i, int j);

#endif
