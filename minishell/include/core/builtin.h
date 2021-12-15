/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 16:31:58 by echung            #+#    #+#             */
/*   Updated: 2021/10/21 17:02:19 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include <unistd.h>

# include "define.h"
# include "core/env/env.h"
# include "lib/libft.h"
# include "core/execute/proc.h"

/**
 * builtin 함수들
 *
 * @param argc 인자 갯수
 * @param argv 인자 들
 * @param env 환경변수 구조체
 * @param fd 출력 fd 값
 * @return 적절한 exit code
 *
 * @example echo -n hello
 * @example argc : 3
 * @example argv : [
 *   'echo',
 *   '-n',
 *   'hello'
 * ]
 * @example fd : 1
 * @example return : 0
 *
 * @note 정상적인 출력 은 출력 fd 값으로
 * @note 에러 메세지는 printf 를 쓰거나, fd 1 로 쓰기
 * @note 함수의 return 값이 프로세스의 exit code 가 됩니다.
 * 
 * @test builtin/test_echo
 * @test builtin/test_cd
 * @test builtin/test_exit
 * @test builtin/test_export
 * @test builtin/test_unset
 */
int	builtin_echo(int argc, char **argv, t_env *env, int fd);
int	builtin_cd(int argc, char **argv, t_env *env, int fd);
int	builtin_pwd(int argc, char **argv, t_env *env, int fd);
int	builtin_export(int argc, char **argv, t_env *env, int fd);
int	builtin_unset(int argc, char **argv, t_env *env, int fd);
int	builtin_env(int argc, char **argv, t_env *env, int fd);
int	builtin_exit(int argc, char **argv, t_env *env, int fd);

#endif
