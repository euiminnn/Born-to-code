/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 22:21:41 by ycha              #+#    #+#             */
/*   Updated: 2021/12/14 17:28:11 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * 쉘을 입력 받습니다.
 *
 * @param line 입력받은 문자열 저장할 주소
 * @return 성공하면 OK 실패하면 ERROR
 */
int	input(char **line)
{
	char	*str;

	str = readline("minishell$ ");
	if (str)
		*line = str;
	else
		return (ERROR);
	add_history(str);
	return (OK);
}
