/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 22:44:09 by echung            #+#    #+#             */
/*   Updated: 2021/11/17 22:44:10 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/parse/parse.h"
#include "utils/utils.h"
#include "core/error.h"

#define BUFFER_SIZE 42000
#define SPACE 1

static int	convert_quote(char *line);
static int	convert_symbol(char *line, char *buf);
static void	revert_quote(char *str);

/**
 * line 에 있는 기호 양 옆에 스페이스를 넣어주고, (따움표 제외)
 * 따움표 안의 스페이스를 SPACE로 바꾸고,
 * ' ' 기준으로 split 한다.
 *
 * @example line : echo hello > abc | cat << abc
 * @example strings : ['echo', 'hello', '>', 'abc', '|', 'cat', '<<' ,'abc']
 */

int	tokenizer(char *line, char ***strings)
{
	char	buf[BUFFER_SIZE];
	int		idx;

	if (!convert_quote(line))
		return (ft_error(ERR_PARSE_MULTI_LINE, 0));
	if (!convert_symbol(line, buf))
		return (ft_error(ERR_PARSE_SYNTAX, 0));
	idx = -1;
	*strings = ft_split(buf, ' ');
	while ((*strings)[++idx])
		revert_quote((*strings)[idx]);
	return (OK);
}

static int	convert_quote(char *str)
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
			if (!*str)
				return (ERROR);
		}
		str++;
	}
	return (OK);
}

static int	convert_symbol(char *line, char *buf)
{
	while (*line)
	{
		if (ft_strchr("();\\", *line))
			return (ERROR);
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
	return (OK);
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
