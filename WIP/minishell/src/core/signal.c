/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 22:29:41 by ycha              #+#    #+#             */
/*   Updated: 2021/11/26 04:09:11 by ycha             ###   ########.fr       */
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
	(void)sig;
	printf("\b\b  \b\b\n");
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
	g_exit_code = 1;
}

void	sigquit_handler(int sig)
{
	(void)sig;
	printf("\b\b  \b\b");
}

void	sigint_handler_in_execute(int sig)
{
	(void)sig;
	printf("\n");
}

void	sigquit_handler_in_execute(int sig)
{
	(void)sig;
	printf("Quit: 3\n");
}
