/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_env.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:17:34 by echung            #+#    #+#             */
/*   Updated: 2021/11/25 21:27:47 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_ENV_H
# define DEBUG_ENV_H

# include "core/env/env.h"

/**
 * 환경 변수 출력
 *
 * @param env 환경 변수 구조체
 */
int		print_env(t_env *env);

/**
 * 디버깅용으로 주어진 환경변수만 들어있는 환경변수로 초기화합니다.
 *
 * @note shlvl 를 처리하지 않습니다.
 *
 * @param envp 환경 변수 문자열
 * @return 초기화된 env (free 필요)
 */
t_env	*init_mock_env(char **envp);

#endif
