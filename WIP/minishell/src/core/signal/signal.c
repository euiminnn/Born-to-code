/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 22:29:41 by ycha              #+#    #+#             */
/*   Updated: 2021/12/13 19:06:48 by ycha             ###   ########.fr       */
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
	printf("\n");
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
	g_exit_code = 1;
}

void	sigquit_handler(int sig)
{
	(void)sig;
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
