/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:19:22 by echung            #+#    #+#             */
/*   Updated: 2021/10/21 17:19:23 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_UTILS_H
# define DEBUG_UTILS_H

# include "define.h"
# include "core/execute/proc.h"
# include "core/error.h"
# include <stdio.h>

/**
 * depth 맞춰 스페이스를 출력합니다.
 *
 * @param depth 깊이
 */
void	print_space(int depth);

/**
 * 문자열 배열을 출력합니다.
 *
 * @param arr 문자열 배열
 * @param depth 깊이
 *
 */
int		print_strings(char **arr, int depth);

/**
 * 에러 종류 이름을 출력합니다.
 *
 * @param errtype 에러 종류
 */
int		print_error_type(int errtype);

#endif
