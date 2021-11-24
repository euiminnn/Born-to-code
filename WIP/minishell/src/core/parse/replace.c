/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 22:43:54 by echung            #+#    #+#             */
/*   Updated: 2021/11/24 19:07:16 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/libft.h"
#include "core/parse/parse.h"
#include "core/parse/token.h"
#include "core/env/env.h"
#include "define.h"

#define DOLLAR 1
#define BUFFER_SIZE 420000

static int	find_dollar(char **str, char **ptr);
static char	*find_key(char *str);
static char	*find_key_from_env(char *key_start, char *key_end, t_env *env);
static char	*remove_quote(char *str);
static void	restore_dollar(char *str);
/**
 * $ 나올때 까지 돌기 ('')
 * $ 나오면, key 찾기, (가능한 key 참고) [a-zA-Z_][a-zA-Z0-9_]*
 * key 에 해당하는 value 를 찾는다
 * value 를 buf 에 붙여넣는다
 * 마지막으로 따옴표를 뻰다.
 */

void	replace_env_in_token(t_token *token, t_env *env)
{
	char	*token_value;
	char	buf[BUFFER_SIZE];
	char	*buf_ptr;
	char	*key_start;
	char	*key_last;
	char	*value;

	buf_ptr = buf;
	token_value = strdup(token->value);
	while (find_dollar(&token_value, &key_start))
	{
		ft_memcpy(buf, token_value, key_start - token_value);
		buf_ptr = buf + (key_start - token_value);
		key_last = find_key(key_start);
		if (key_start + 1 == key_last)
			*buf_ptr++ = DOLLAR;
		else
		{
			value = find_key_from_env(key_start, key_last, env);
			if (value)
			{			
				ft_memcpy(buf_ptr, value, ft_strlen(value));
				buf_ptr += ft_strlen(value);
				free(value);
			}
		}
		ft_memcpy(buf_ptr, key_last, ft_strlen(key_last));
		buf_ptr += ft_strlen(key_last);
		*buf_ptr = '\0';
		free(token_value);
		token_value = ft_strdup(buf);
	}
	if (*token_value == '\0' && *token->value != '\0')
		token->type = T_DELETE;
	free(token->value);
	token->value = remove_quote(token_value);
	restore_dollar(token->value);
}

static int	find_dollar(char **str, char **ptr)
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

static char	*find_key(char *str)
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

static char	*find_key_from_env(char *key_start, char *key_end, t_env *env)
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

static char	*remove_quote(char *str)
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

static void	restore_dollar(char *str)
{
	while (*str)
	{
		if (*str == DOLLAR)
			*str = '$';
		str++;
	}
}
