/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 20:52:07 by ycha              #+#    #+#             */
/*   Updated: 2022/04/25 19:47:42 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H
# include <fcntl.h>
# include "minirt.h"
# define WHITESPACE "\t\n\v\f\r "
# define MAX_FILE_READ 4400000

typedef struct s_minirt	t_minirt;

typedef enum e_parsable
{
	a = 0,
	c,
	l,
	sp,
	pl,
	cy
}	t_parsable;

int	input(int argc, char **argv);
int	parse_split(t_vec *input, char *line);
int	free_line(char **line, char **words);

int	parse_a(char **line);
int	parse_c(char **line);
int	parse_l(char **line);
int	parse_pl(char **line);
int	parse_sp(char **line);
int	parse_cy(char **line);

#endif
