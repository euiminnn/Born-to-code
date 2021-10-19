/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 16:26:07 by echung            #+#    #+#             */
/*   Updated: 2021/10/20 02:48:29 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNAL_H
# define SIGNAL_H

# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>

# include "define.h"

/**
 * 이전 시그널 함수를 저장할 구조체
 *
 * @p sigint 기존 sigint handler
 * @p sigquit 기존 sigquit handler
 */
typedef struct s_signal_handler
{
	void	(*sigint)();
	void	(*sigquit)();
}	t_signal_handler;

/**
 * signal_handler 에 접근할 수 있는 포인터를 제공합니다.
 *
 * @return t_signal_handler 구조체 포인터
 */
t_signal_handler	*sig_handler(void);

/**
 * SIGINT 에 대해서 쉘이 받는 시그널을 처리합니다.
 *
 * @details 프롬포트를 다시 띄우는 처리를 합니다.
 *
 * @param sig 시그널
 */
void				sigint_handler(int sig);

/**
 * SIGQUIT 에 대해서 쉘이 받는 시그널을 처리합니다.
 *
 * @details ^\을 지우는 행동을 합니다.
 *
 * @param sig 시그널
 */
void				sigquit_handler(int sig);

/**
 * SIGINT 에 대해서 자식 프로레스가 처리되는 동안의 시그널을 처리합니다.
 *
 * @details 안하도록 합니다.
 *
 * @param sig 시그널
 */
void				sigint_handler_in_execute(int sig);

/**
 * SIGQUIT 에 대해서 자식 프로세스가 처리되는 동안의 시근러을 처리합니다.
 *
 * @details Quit :3 을 출력하도록 합니다
 *
 * @param sig 시그널
 */
void				sigquit_handler_in_execute(int sig);

#endif
