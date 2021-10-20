/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 02:51:17 by ycha              #+#    #+#             */
/*   Updated: 2021/10/20 02:51:18 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include <stdlib.h>
# include <stdio.h>

# include "define.h"
# include "utils/list.h"
# include "core/env/env_data.h"

/**
 * @file 환경 변수 제어 관련 헤더 입니다.
 * 
 * @note 환경 변수란?
 * @note key=value 형태로 되어서 쉘 내부에서 전역 변수처럼 사용된다.
 */

/**
 * @brief 이미 구현되어있는 연결리스트를 그대로 사용하여 환경 변수를 구현합니다.
 * 
 * @details 환경 변수 구현 구조
 * key, value 값은 t_env_data 에 저장하고,
 * 연결리스트의 노드의 data 로 t_end_data 를 사용합니다.
 * 
 * @ref env_data.h
 */
typedef t_list t_env;

/**
 * 환경 변수를 초기홥니다.
 * 
 * @param envp 환경 변수 문자열
 * @return 초기화된 env (free 필요)
 */
t_env   *init_env(char **envp);

/**
 * 환경 변수에서 key의 value 값을 찾습니다.
 * 
 * @param env 환경 변수 구조체
 * @param str 검색할 key 값
 * @return key 에 해당하는 value 값, 없을 경우 NULL
 * 
 * @test env/test_search
 */
char    *search_env(t_env *env, char *key);

/**
 * 환경 변수에 값을 추가합니다.
 * 
 * @param env 환경 변수 구조체
 * @param key 추가할 key 값
 * @param value 추가할 value 값 (없는 경우 NULL)
 * 
 * @test env/test_insert
 */
void    insert_env(t_env *env, char *key, char *value);

/**
 * 환경 변수에서 key에 해당하는 value 값을 수정합니다.
 * 
 * @param env 환경 변수 구조체
 * @param key 변경할 key 값
 * @param value 변경될 value 값
 * @return key를 못찾으면 ERROR, 성공시 OK
 * 
 * @test env/test_change
 */
int change_env(t_env *env, char *key, char *value);

/**
 * 환경 변수에서 key값을 삭제합니다.
 * 
 * @param env 환경 변수 구조체
 * @param key 삭제할 key 값
 * @return key를 못찾으면 ERROR, 성공시 OK
 * 
 * @test env/test_remove
 */
int remove_env(t_env *env, char *key);

/**
 * 환경 변수 메모리를 해제합니다.
 * 
 * @param env 환경 변수 구조체
 */
void    free_env(t_env *env);

/**
 * 주어진 함수에 따라 환경 변수를 이차원 문자열로 변환합니다.
 * 
 * @param env 환경 변수 구조체
 * @param to_string 환경 변수 데이터 구조체를 문자열로 변환 시킬 함수
 * @return 이차원 문자열 (free 필요)
 */
char    **to_string_env(t_env *env, char *(*to_string)(t_env_data *data));

#endif
