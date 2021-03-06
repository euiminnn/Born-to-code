/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 16:26:07 by echung            #+#    #+#             */
/*   Updated: 2021/09/12 16:31:50 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

void	mshell_echo(int argc, char **argv, char **env);
void	mshell_cd(int argc, char **argv, char **env);
void	mshell_pwd(int argc, char **argv, char **env);

#endif
