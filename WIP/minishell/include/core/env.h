#ifndef ENV_H
#define ENV_H

#include <stdlib.h>
#include <stdio.h>
#include "define.h"
#include "utils/list.h"

/**
 * 환경 변수란?
 * 
 * key=value 형태로 되어서
 * 쉘 내부에서 전역 변수처럼 사용된다.
 */

/**
 * @brief 환경 변수값들이 담길 연결리스트
 * 
 * @c key 환경 변수에서 key 에 해당됨 
 * @c value : 환경 변수에서 value 에 해당됨 (value 가 없는 경우 NULL)
 * @c next : 다음 연결 리스트 포인터
 * 
 * @example {
 *   key : 'USER'
 *   value : 'ycha'
 *   next : pointer
 * }
 */
typedef struct s_env
{
    char *key;
    char *value;
    struct s_env *next;
}   t_env;

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
 */
char    *search_env(t_env *env, char *key);

/**
 * 환경 변수에 값을 추가합니다.
 * 
 * @param env 환경 변수 구조체
 * @param key 추가할 key 값
 * @param value 추가할 value 값 (없는 경우 NULL)
 */
void    insert_env(t_env *env, char *key, char *value);

/**
 * 환경 변수에서 key에 해당하는 value 값을 수정합니다.
 * 
 * @param env 환경 변수 구조체
 * @param key 변경할 key 값
 * @param value 변경될 value 값
 */
void    change_env(t_env *env, char *key, char *value);

/**
 * 환경 변수에서 key값을 삭제합니다.
 * 
 * @param env 환경 변수 구조체
 * @param key 삭제할 key 값
 */
void    remove_env(t_env *env, char *key);

/**
 * 환경 변수 메모리를 해제합니다.
 * 
 * @param env 환경 변수 구조체
 */
void    free_env(t_env *env);

/**
 * 환경 변수를 이차원 문자열로 추출합니다.
 * 
 * @example ["key1=value", "key2=value"]
 * 
 * @param env 환경 변수 구조체
 * @return 이차원 문자열 (free 필요)
 */
char    **export_env(t_env *env);

#endif
