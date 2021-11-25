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
#include "core/parse/replace.h"
#include "core/env/env.h"
#include "define.h"

#define DOLLAR 1
#define BUFFER_SIZE 420000

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
	restore_dollar(token_value);
	token->value = remove_quote(token_value);
}
