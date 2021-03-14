/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjung <gjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 13:39:33 by gjung             #+#    #+#             */
/*   Updated: 2021/02/02 12:49:16 by gjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		is_newline(char *buffer)
{
	int			i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int		split_line(char **buffer, char **line, int cut_idx)
{
	char		*temp;
	int			len;

	(*buffer)[cut_idx] = '\0';
	*line = ft_strdup(*buffer);
	len = ft_strlen(*buffer + cut_idx + 1);
	if (len == 0)
	{
		free(*buffer);
		*buffer = 0;
		return (1);
	}
	temp = ft_strdup(*buffer + cut_idx + 1);
	free(*buffer);
	*buffer = temp;
	return (1);
}

int		return_all(char **buffer, char **line, int read_size)
{
	int			cut_idx;

	if (read_size < 0)
		return (-1);
	if (*buffer && (cut_idx = is_newline(*buffer)) >= 0)
		return (split_line(buffer, line, cut_idx));
	else if (*buffer)
	{
		*line = *buffer;
		*buffer = 0;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	*buffer[OPEN_MAX];
	char		*temp;
	char		rd_buffer[BUFFER_SIZE + 1];
	int			len;
	int			i;

	if ((fd < 0) || (line == 0) || (BUFFER_SIZE <= 0))
		return (-1);
	while ((len = read(fd, rd_buffer, BUFFER_SIZE)) > 0)
	{
		rd_buffer[len] = '\0';
		temp = ft_strjoin(buffer[fd], rd_buffer);
		if (buffer[fd] != 0)
			free(buffer[fd]);
		buffer[fd] = temp;
		if ((i = is_newline(buffer[fd])) >= 0)
			return (split_line(&buffer[fd], line, i));
	}
	return (return_all(&buffer[fd], line, len));
}
