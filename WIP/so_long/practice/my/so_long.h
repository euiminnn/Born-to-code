/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 00:43:58 by echung            #+#    #+#             */
/*   Updated: 2021/08/06 02:01:55 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct s_param{
	int		x;
	int		y;
	char	str[3];
}				t_param;

int				key_press(int keycode);
void			param_init(t_param *param);
char	**readfile(char *filename);
int		count_gnl(char *filename);
int			get_next_line(int fd, char **line);
static int	save_line(char **str, char **line, int index);
int	find_index(char *s, char c);
void	*ft_memcpy(void *dst, const void *src, int n);
char	*ft_strdup(const char *src);
char	*ft_strjoin_free(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, int len);
int	ft_strlen(const char *str);

int	parse_map(char **arr, int row, int column);
int	is_instring(int c, char *s);

#endif
