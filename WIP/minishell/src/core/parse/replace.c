#include "lib/libft.h"
#include "core/parse/parse.h"
#include "core/parse/token.h"
#include "core/env.h"

#define BUFFER_SIZE 420000
#define CHARSET "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_"
#define CHARSET_WITH_DIGIT \
		"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_0123456789"

static int find_dallor(char **ptr, char **buf);
static char	*find_key(char *str);
static char	*find_key_from_env(char *key_start, char *key_end, t_env *env);
static char *remove_quote(char *str);

/**
 * $ 나올때 까지 돌기 ('')
 * $ 나오면, key 찾기, (가능한 key 참고) [a-zA-Z_][a-zA-Z0-9_]*
 * key 에 해당하는 value 를 찾는다
 * value 를 buf 에 붙여넣는다
 *
 * @example abc"hello$USER asdf"abc
 * @example abc"helloycha asdf"abc
 * @example abchelloycha asdfabc
 *
 */
int replace_env_in_token(t_token *token, t_env *env)
{
	char	buf[BUFFER_SIZE];
	char	*buf_ptr;
	char	*str_ptr;
	char	*key_last_ptr;
	char	*value;

	buf_ptr = buf;
	str_ptr = token->value;
	while (find_dallor(&str_ptr, &buf_ptr))
	{
		printf("is dallar? %c\n", *str_ptr);
		key_last_ptr = find_key(str_ptr);
		printf("is key last? %c\n", *key_last_ptr);
		value = find_key_from_env(str_ptr, key_last_ptr, env);
		printf("is value? %s\n", value);
		if (value)
		{
			ft_memcpy(buf_ptr, value, ft_strlen(value));
			buf_ptr += ft_strlen(value);
		}
		str_ptr = key_last_ptr;
	}
	*buf_ptr = '\0';
	free(token->value);
	token->value = remove_quote(buf);
	return (OK);
}

static int find_dallor(char **ptr, char **buf)
{
	while (**ptr)
	{
		if(**ptr == '$')
			return (OK);
		*(*buf)++ = *(*ptr)++;
		if (**ptr == '\'')
			while (**ptr && **ptr != '\'')
				*(*buf)++ = *(*ptr)++;
	}
	return (ERROR);
}

static char	*find_key(char *str)
{
	int		index;
	char	*charset;

	index = 1;
 	while (str[index])
	{
		charset = CHARSET_WITH_DIGIT;
		if (index == 1)
			charset = CHARSET;
		if (ft_strchr(charset, str[index]))
			++index;
		else
			break;
	}
	return (&str[index]);
}

static char	*find_key_from_env(char *key_start, char *key_end, t_env *env)
{
	char	key_end_value;
	char	*value;

	key_end_value = *key_end;
	*key_end = '\0';
	value = search_env(env, key_start + 1);
	*key_end = key_end_value;
	return (value);
}

static char *remove_quote(char *str)
{
	char	buf[BUFFER_SIZE];
	int		idx;

	idx = 0;
	while (*str)
	{
		if (*str == '\'' || *str == '\"')
		{
			str++;
			continue ;
		}
		buf[idx] = *str;
		idx++;
		str++;
	}
	buf[idx] = '\0';
	return (ft_strdup(buf));
}
