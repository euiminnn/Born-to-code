/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlugand- <vlugand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 15:47:19 by vlugand-          #+#    #+#             */
/*   Updated: 2020/03/02 22:10:37 by vlugand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		find_index(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i] && s[i] != (char)c)
		i++;
	if (s[i] != (char)c)
		return (-1);
	return (i);
}

int		get_line(char *str, char **line, int i)
{
	int		len;

	*line = ft_substr(str, 0, i);
	++i;
	len = ft_strlen(str + i) + 1;
	ft_memmove(str, str + i, len);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	char			buff[BUFFER_SIZE + 1];
	static char		*str[OPEN_MAX];
	int				ret;
	int				i;

	if (!line || fd < 0 || BUFFER_SIZE < 1 || read(fd, buff, 0) < 0)
		return (-1);
	if (str[fd] && (((i = find_index(str[fd], '\n')) != -1)))
		return (get_line(str[fd], line, i));
	while (((ret = read(fd, buff, BUFFER_SIZE)) > 0))
	{
		buff[ret] = '\0';
		str[fd] = join_and_free(str[fd], buff);
		if (((i = find_index(str[fd], '\n')) != -1))
			return (get_line(str[fd], line, i));
	}
	if (str[fd])
	{
		*line = ft_strdup(str[fd]);
		free(str[fd]);
		str[fd] = NULL;
		return (ret);
	}
	*line = ft_strdup("");
	return (ret);
}
