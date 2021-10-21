/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:32:39 by echung            #+#    #+#             */
/*   Updated: 2021/10/21 17:38:27 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "lib/libft.h"

# include "define.h"
# include <stdio.h>
# include <string.h>

/**
 * close 함수를 안전하게 사용합니다.
 * 
 * @details stdin, stdout, stderr 는 닫지 않도록 합니다.
 * 
 * @param fd 닫을 fd 값
 */
void	ft_close(int fd);

/**
 * dup2 를 안전하게 사용합니다.
 * 
 * @details 같은 fd 면 dup2 을 하지 않습니다
 * @details 정상적으로 dup2가되면 fd 를 닫습니다.
 * 
 * @param fd1 fd 값
 * @param fd2 fd 값
 * @return dup2 의 return 과 동일
 */
int		ft_dup(int fd1, int fd2);

/**
 * 에러번호에 따라 오류를 출력하고 exit 합니다.
 * 
 * @param err 에러번호
 */
void	ft_exit(int err);

/**
 * 문자열 배열의 메모리를 해제합니다.
 * 
 * @param arr 문자열 배열 메모리
 */
void	ft_free_strings(char **arr);

/**
 * str 에서 첫번째 = 을 기준으로 key 와 value 를 가져옵니다.
 * 
 * @warning key 와 value 를 꼭 free 해주세요.
 * 
 * @param str 문자열
 * @param key key 문자열 포인터 (free 필요)
 * @param value value 문자열 포인터 (없을경우 NULL, free 필요)
 */
void	ft_get_key_value(char *str, char **key, char **value);

/**
 * 문자열 여러개를 합칩니다.
 * 
 * @param strs 문자열 배열
 * @param n 문자열 갯수
 * @return 합쳐진 문장려
 * 
 * @example 간단한 함수 사용 예시
 * 
 * str = "world!";
 * result = ft_strjoins((char *[3]){"hello", str, "\n"}, 3);
 * printf("%s", result); // "helloworld!\n" 가 출력된다.
 */
char	*ft_strjoins(char **strs, int n);

#endif
