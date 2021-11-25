/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:19:22 by echung            #+#    #+#             */
/*   Updated: 2021/11/25 20:45:22 by ycha             ###   ########.fr       */
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

#endif
