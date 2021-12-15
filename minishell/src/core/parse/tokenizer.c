/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 22:44:09 by echung            #+#    #+#             */
/*   Updated: 2021/11/24 19:18:26 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/parse/parse.h"
#include "utils/utils.h"
#include "core/error.h"

#define BUFFER_SIZE 42000
#define SPACE 1

static void	convert_quote(char *line);
static void	convert_symbol(char *line, char *buf);
static void	revert_quote(char *str);

/**
 * line 에 있는 기호 양 옆에 스페이스를 넣어주고, (따움표 제외)
 * 따움표 안의 스페이스를 SPACE로 바꾸고,
 * ' ' 기준으로 split 한다.
 *
 * @example line : echo hello > abc | cat << abc
 * @example strings : ['echo', 'hello', '>', 'abc', '|', 'cat', '<<' ,'abc']
 */

void	tokenizer(char *line, char ***strings)
{
	char	buf[BUFFER_SIZE];
	int		idx;

	convert_quote(line);
	convert_symbol(line, buf);
	idx = -1;
	*strings = ft_split(buf, ' ');
	while ((*strings)[++idx])
		revert_quote((*strings)[idx]);
}

static void	convert_quote(char *str)
{
	char	quote;

	while (*str)
	{
		if (*str == '\'' || *str == '\"')
		{
			quote = *str;
			str++;
			while (*str && *str != quote)
				*str++ *= -1;
		}
		str++;
	}
}

static void	convert_symbol(char *line, char *buf)
{
	while (*line)
	{
		if (ft_strchr("<>|", *line))
		{
			*buf++ = ' ';
			*buf++ = *line;
			if (*line == *(line + 1))
				*buf++ = *line++;
			*buf = ' ';
		}
		else
			*buf = *line;
		++buf;
		++line;
	}
	*buf = '\0';
}

static void	revert_quote(char *str)
{
	while (*str)
	{
		if (*str < 0)
			*str *= -1;
		++str;
	}
}
