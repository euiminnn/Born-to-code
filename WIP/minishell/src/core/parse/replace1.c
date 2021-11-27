/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 22:43:54 by echung            #+#    #+#             */
/*   Updated: 2021/11/27 22:11:15 by echung           ###   ########.fr       */
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

static int	copy_key_to_buf( \
	char *buf_ptr, \
	char *key_start, \
	char *key_last, \
	t_env *env\
);

void	replace_tilde_in_token(t_token *token, t_env *env)
{
	char	buf[BUFFER_SIZE];
	char	*str;
	char	*home;

	str = token->value;
	if (str[0] == '~' && (str[1] == '\0' || str[1] == '/'))
	{
		home = search_env(env, "HOME");
		ft_memcpy(buf, home, ft_strlen(home));
		ft_memcpy(buf + ft_strlen(home), str + 1, ft_strlen(str + 1));
		buf[ft_strlen(home) + ft_strlen(str + 1)] = '\0';
		free(token->value);
		token->value = ft_strdup(buf);
	}
}

/**
 * $ 나올때 까지 돌기 ('')
 * $ 나오면, key 찾기, (가능한 key 참고) [a-zA-Z_][a-zA-Z0-9_]*
 * key 에 해당하는 value 를 찾는다
 * value 를 buf 에 붙여넣는다
 * 마지막으로 따옴표를 뻰다.
 */

void	replace_env_in_token(t_token *token, t_env *env)
{
	char	*str;
	char	buf[BUFFER_SIZE];
	char	*buf_ptr;
	char	*key_start;
	char	*key_last;

	buf_ptr = buf;
	str = ft_strdup(token->value);
	while (find_dollar(&str, &key_start))
	{
		ft_memcpy(buf, str, key_start - str);
		buf_ptr = buf + (key_start - str);
		key_last = find_key(key_start);
		buf_ptr += copy_key_to_buf(buf_ptr, key_start, key_last, env);
		ft_memcpy(buf_ptr, key_last, ft_strlen(key_last));
		buf_ptr += ft_strlen(key_last);
		*buf_ptr = '\0';
		free(str);
		str = ft_strdup(buf);
	}
	if (*str == '\0' && *token->value != '\0')
		token->type = T_DELETE;
	free(token->value);
	token->value = remove_quote(restore_dollar(str));
	free(str);
}

static int	copy_key_to_buf( \
	char *buf_ptr, \
	char *key_start, \
	char *key_last, \
	t_env *env\
)
{
	char	*value;

	if (key_start + 1 == key_last)
	{
		*buf_ptr = DOLLAR;
		return (1);
	}
	value = find_key_from_env(key_start, key_last, env);
	if (value)
	{			
		ft_memcpy(buf_ptr, value, ft_strlen(value));
		free(value);
		return (ft_strlen(value));
	}
	return (0);
}
