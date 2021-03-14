/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 20:26:15 by echung            #+#    #+#             */
/*   Updated: 2021/02/12 23:01:46 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_index(const char *s, char c)
{
	int		index;
	
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

int	save_line(char **str, char **line, int index)
{
	char	*temp;

	*line = ft_substr(*str, 0, index);				//str에서 개행 '앞'까지 잘라 line에 넣는다
	temp = ft_substr(*str, index + 1, ft_strlen(*str) - index - 1);	//개행 뒤부터 나머지 저장해둔다
	free(*str);
	*str = temp;
	return (1);									//읽었으면 1 리턴
}

int	get_next_line(int fd, char **line)
{
	char		 buff[BUFFER_SIZE + 1];
	static char	*str;
	int			ret;
	int			i_nl;

	if (fd < 0 || !line || BUFFER_SIZE < 1 || read(fd, buff, 0) < 0)	//오류일 때 -1 반환
		return (-1);
	if (str && ((i_nl = find_index(str, '\n')) != -1))		//str에 내용 남고 개행 있다면
		return (save_line(&str, line, i_nl));
	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)		//읽은 바이트가 있다면
	{
		buff[ret] = '\0';								//읽은 만큼 자른다
		str = ft_strjoin_free(str ? str : ft_strdup(""), buff);		//str + buff 합친다
		if (((i_nl = find_index(str, '\n')) != -1))			//개행이 어디있는지 찾는다. 있어야만 탈출 가능(?)
			return (save_line(&str, line, i_nl));
	}
	if (str)											//str에 내용 남았는데 개행없다면(마지막줄)
	{
		*line = ft_strdup(str);
		free(str);
		str = NULL;
		return (0);										//나머지 str은 line으로 반환하고, 0리턴 
	}
	*line = ft_strdup("");
	return (0);											//str에 남은거 없다면 = 파일 끝
}
