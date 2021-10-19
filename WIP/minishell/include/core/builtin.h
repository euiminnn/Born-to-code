/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 16:31:58 by echung            #+#    #+#             */
/*   Updated: 2021/09/12 16:32:43 by echung           ###   ########.fr       */
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
 * @return 정상 종료하면 0, 오류 있으면 그 이외의 값
 *
 * @example echo -n hello
 * @example argc : 3
 * @example argv : [
 *   'echo',
 *   '-n',
 *   'hello'
 * ]
 *
 * @test builtin/test_echo
 * @test builtin/test_exit
 * @test builtin/test_export
 * @test builtin/test_unset
 */
int    builtin_echo(int argc, char **argv, t_env *env, int fd);
int    builtin_cd(int argc, char **argv, t_env *env, int fd);
int    builtin_pwd(int argc, char **argv, t_env *env, int fd);
int    builtin_export(int argc, char **argv, t_env *env, int fd);
int    builtin_unset(int argc, char **argv, t_env *env, int fd);
int    builtin_env(int argc, char **argv, t_env *env, int fd);
int    builtin_exit(int argc, char **argv, t_env *env, int fd);

#endif
