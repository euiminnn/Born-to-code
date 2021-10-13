/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 16:31:58 by echung            #+#    #+#             */
/*   Updated: 2021/09/12 16:32:43 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include <unistd.h>

void	builtin_echo(int argc, char **argv, char **env);
void	builtin_cd(int argc, char **argv, char **env);
void	builtin_pwd(int argc, char **argv, char **env);

#endif
