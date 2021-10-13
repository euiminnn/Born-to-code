/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mshell_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 16:26:55 by echung            #+#    #+#             */
/*   Updated: 2021/10/13 16:44:59 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/builtin.h"
#include "core/env.h"

/**
 * 
 * @example argv ['export', 'ABC=10']
 * 
 * 
 * 
 */
void	builtin_exit(int argc, char **argv, t_env *env)
{
    (void)argc;
    (void)argv;
    (void)env;

    

    insert_env(env, 'ABC', '10')
    remove_env
    search_env

	exit(0);
}
