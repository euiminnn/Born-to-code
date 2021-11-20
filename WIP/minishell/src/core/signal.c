/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 22:29:41 by ycha              #+#    #+#             */
/*   Updated: 2021/11/20 22:29:54 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/signal.h"

t_signal_handler	*sig_handler(void)
{
	static t_signal_handler	signals;

	return (&signals);
}

void	sigint_handler(int sig)
{
	printf("\b\b  \b\b\n");
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
	g_exit_code = 1;
}

void	sigquit_handler(int sig)
{
	printf("\b\b  \b\b");
}

void	sigint_handler_in_execute(int sig)
{
	printf("\n");
}

void	sigquit_handler_in_execute(int sig)
{
	printf("Quit: 3\n");
}
