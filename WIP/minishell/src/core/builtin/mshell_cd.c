/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mshell_cd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 16:23:34 by echung            #+#    #+#             */
/*   Updated: 2021/09/12 16:33:15 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

/*
 * cd github
 * argc : 2
 * argv : {"cd", "github"}
 * env : ...
 */
void	mshell_cd(int argc, char **argv, char **env)
{
	chdir(argv[1]);
}
