/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 20:25:36 by ycha              #+#    #+#             */
/*   Updated: 2021/11/25 20:25:36 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/libft.h"
#include "core/parse/parse.h"
#include "core/parse/token.h"
#include "core/parse/replace.h"
#include "core/env/env.h"
#include "define.h"

#define DOLLAR 1
#define BUFFER_SIZE 420000

int	find_dollar(char **str, char **ptr)
{
	*ptr = *str;
	while (**ptr)
	{
		if (**ptr == '$')
			return (TRUE);
		else if (**ptr == '\'')
		{
			(*ptr)++;
			while (**ptr && **ptr != '\'')
				(*ptr)++;
		}
		else if (**ptr == '\"')
		{
			(*ptr)++;
			while (**ptr && **ptr != '\"')
			{
				if (**ptr == '$')
					return (TRUE);
				(*ptr)++;
			}
		}
		if (**ptr)
			(*ptr)++;
	}
	return (FALSE);
}

char	*find_key(char *str)
{
	int		index;
	char	*charset;

	index = 1;
	if (ft_isdigit(str[1]))
		return (str + 2);
	if (str[1] == '?')
		return (str + 2);
	while (str[index])
	{
		charset = CHARSET_WITH_DIGIT;
		if (index == 1)
			charset = CHARSET_WITH_Q;
		if (ft_strchr(charset, str[index]))
			++index;
		else
			break ;
	}
	return (&str[index]);
}

char	*find_key_from_env(char *key_start, char *key_end, t_env *env)
{
	char	key_end_value;
	char	*value;
	char	*ret;

	ret = 0;
	key_end_value = *key_end;
	*key_end = '\0';
	if (key_start[1] == '?')
		ret = ft_itoa(g_exit_code);
	else
	{
		value = search_env(env, &key_start[1]);
		if (value)
			ret = ft_strdup(value);
	}
	*key_end = key_end_value;
	return (ret);
}

void	restore_dollar(char *str)
{
	while (*str)
	{
		if (*str == DOLLAR)
			*str = '$';
		str++;
	}
}

char	*remove_quote(char *str)
{
	char	buf[BUFFER_SIZE];
	char	*quote_start;
	int		idx;

	idx = 0;
	while (*str)
	{
		if (*str == '\'' || *str == '\"')
		{
			quote_start = str;
			str++;
			while (*str && *str != *quote_start)
				str++;
			if (*str == *quote_start)
				quote_start++;
			ft_memcpy(buf + idx, quote_start, str - (quote_start));
			idx += (str - (quote_start));
			if (*str)
				str++;
		}
		else
			buf[idx++] = *str++;
	}
	buf[idx] = '\0';
	return (ft_strdup(buf));
}
