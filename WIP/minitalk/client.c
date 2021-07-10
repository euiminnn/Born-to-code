/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 18:55:53 by echung            #+#    #+#             */
/*   Updated: 2021/07/10 19:16:07 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	client(int pid, char *str)
{
	kill(pid, SIGUSR1);
	kill(pid, SIGUSR2);
}

int 	main(int argc, char **argv)
{
	client(pid, argv[2]);
}
