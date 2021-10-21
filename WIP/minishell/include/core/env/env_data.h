/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_data.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:06:50 by echung            #+#    #+#             */
/*   Updated: 2021/10/21 17:25:29 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_DATA_H
# define ENV_DATA_H

# include <stdlib.h>
# include <stdio.h>
# include "define.h"
# include "utils/list.h"

/**
 * @brief 환경 변수값이 담긴 구조체
 * 
 * @note t_env 연결리스트의 data 에 해당됨.
 * 
 * @c key 환경 변수에서 key 에 해당됨 
 * @c value : 환경 변수에서 value 에 해당됨 (value 가 없는 경우 NULL)
 * 
 * @example {
 *   key : 'USER'
 *   value : 'ycha'
 * }
 */
typedef struct s_env_data
{
	char	*key;
	char	*value;
}	t_env_data;

/**
 * 환경 변수 메모리를 해제합니다.
 * 
 * @param env 환경 변수 구조체
 */
t_env_data	*init_env_data(char *key, char *value);

/**
 * 환경 변수 데이터 구조체 메모리를 해제합니다.
 * 
 * @param data 환경 변수 데이터 구조체
 */
void		free_env_data(void *data);

/**
 * 환경 변수 데이터 구조체를 문자열로 변경합니다.
 * 
 * @return 문자열, value 가 없으면 NULL
 */
char		*to_string_env_data(t_env_data *data);

#endif
