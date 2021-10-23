/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 16:33:40 by echung            #+#    #+#             */
/*   Updated: 2021/10/23 15:10:54 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/builtin.h"
#include "core/env/env.h"

// env 구조 바뀌면서 ycha 가 추가했음....
// 가능하면 builtin_export_only 도 이와 비슷한 형식으로 해보면 좋을거같음...
// 사실 꼭 그럴필요는 없음... 그래도 해보겠다면, 
// 기벼운 함수 포인터랑 문자열 배열 개념이 필요함...
// 그리고 ft_strjoins의 사용법을 알아야함.....
// ft_strjoins 의 사용법은 헤더 utils/utils.h 에 자세히 적혀있음...
// 읽었으면 주석 지워주세요
static char	*to_string(t_env_data *data)
{
	if (!data->value)
		return (NULL);
	return (ft_strjoins((char *[4]){data->key, "=", data->value, "\n"}, 4));
}

int	builtin_env(int argc, char **argv, t_env *env, int fd)
{
	char	**envp;
	int i;

	i = 0;
	envp = to_string_env(env, to_string);
	while (envp[i])
	{
		ft_putstr_fd(envp[i], fd);
		i++;
	}
/*
	for (i = 0; env[i] != NULL; i++)
		printf("\n%s", env[i]);
*/
	return (0);
}
