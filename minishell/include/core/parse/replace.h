/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 20:24:42 by ycha              #+#    #+#             */
/*   Updated: 2021/11/26 04:05:26 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_H
# define REPLACE_H
/**
 * 문자열에서 $ 를 찾습니다.
 * 
 * @param str 원본 문자열
 * @param ptr 원본 문자열에서, 찾은 $ 를 가리킬 포인터
 * @return 검색에 성공하면 OK, 실패하면 ERROR 
 */
int		find_dollar(char **str, char **ptr);

/**
 * $ 뒤에있는 유효한 key 값을 찾습니다.
 * 
 * @param str $ 가리키는 포인터
 * @return key 문자열 바로 다음 포인터
 * 
 * @example $USER 에서, str은 $를 가리키고, return 값은 R 뒤의 공백
 */
char	*find_key(char *str);

/**
 * key 문자열을 통하여 환경변수에 대응하는 value 를 찾습니다
 * 
 * @param key_start key 문자열 시작점
 * @param key_end key 문자열 종료점
 * @param env 환경변수 구조체
 * @return 검색한 value 값, 없을경우 null
 */
char	*find_key_from_env(char *key_start, char *key_end, t_env *env);

/**
 * DOLLAR 로 변경되어있는 $를 다시 $로 돌려놓습니다.
 * 
 * @param str 변경할 문자열
 * @return 변경된 문자열
 */
char	*restore_dollar(char *str);

/**
 * 짝이 맞는 quote 를 지웁니다.
 * 
 * @param str 지울 문자열
 * @return 지워진 문자열 (free 필요)
 */
char	*remove_quote(char *str);

#endif
