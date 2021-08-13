/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 22:42:21 by echung            #+#    #+#             */
/*   Updated: 2021/08/10 18:22:20 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#define BUFFER_SIZE 1

int	find_index(char *s, char c)
{
	int	index;

	index = 0;
	while (*s != '\0')
	{
		if (*s == c)
			return (index);
		s++;
		index++;
	}
	return (-1);
}

static int	save_line(char **str, char **line, int index)
{
	char	*temp;

	*line = ft_substr(*str, 0, index);
	temp = ft_substr(*str, index + 1, ft_strlen(*str) - index - 1);
	free(*str);
	*str = temp;
	return (1);
}

int	get_next_line_sub(char **str, char **line)
{
	*line = ft_strdup(*str);
	free(*str);
	*str = NULL;
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*str;
	int			ret;
	char		buff[BUFFER_SIZE + 1];
	int			i_nl;

	if (fd < 0 || !line || BUFFER_SIZE < 1 || read(fd, buff, 0) < 0)
		return (-1);
	if (str)
		i_nl = find_index(str, '\n');
	if (str && (i_nl != -1))
		return (save_line(&str, line, i_nl));
	ret = read(fd, buff, BUFFER_SIZE);
	while (ret > 0)
	{
		buff[ret] = '\0';
		str = ft_strjoin_free_sub(str, buff);
		i_nl = find_index(str, '\n');
		if (i_nl != -1)
			return (save_line(&str, line, i_nl));
		ret = read(fd, buff, BUFFER_SIZE);
	}
	if (str)
		return (get_next_line_sub(&str, line));
	*line = ft_strdup("");
	return (0);
}
