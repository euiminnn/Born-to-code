/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:12:55 by echung            #+#    #+#             */
/*   Updated: 2021/10/21 17:12:56 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIR_H
# define REDIR_H

# include <stdio.h>
# include <readline/readline.h>
# include <fcntl.h>
# include <unistd.h>

/**
 * 왼쪽 리다이렉션 (<) 을 처리합니다. 
 * 
 * @param file 파일이름
 * @return 파일을 열어서 나온 fd값 
 */
int	left_redir(char *file);

/**
 * 왼쪽 이중 리다이렉션 (<<) 을 처리합니다. 
 * 
 * @param limiter fd 문자열
 * @return fd 값
 */
int	left_double_redir(char *fd);

/**
 * 오른쪽 리다이렉션 (>) 을 처리합니다. 
 * 
 * @param file 파일이름
 * @return 파일을 열어서 나온 fd값 
 */
int	right_redir(char *file);

/**
 * 오른쪽 이중 리다이렉션 (>>) 을 처리합니다. 
 * 
 * @param file 파일이름
 * @return 파일을 열어서 나온 fd값 
 */
int	right_double_redir(char *file);

#endif
