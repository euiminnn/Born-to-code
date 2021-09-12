/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mshell_pwd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 16:26:55 by echung            #+#    #+#             */
/*   Updated: 2021/09/12 16:37:49 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#define PATH_MAX 1000

void	mshell_pwd(int argc, char **argv, char **env)
{
	char cwd[PATH_MAX];

   	if (getcwd(cwd, sizeof(cwd)) != NULL)
       printf("%s\n", cwd);
}

