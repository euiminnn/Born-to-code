/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:03:08 by echung            #+#    #+#             */
/*   Updated: 2021/11/26 03:11:54 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include <stdio.h>

# include "define.h"

# define ERR_PARSE_SYNTAX 258
# define ERR_EXECUTE_REDIR_NO_FILE 1
# define ERR_EXECTUE_COMMAND_IS_DIRECTORY 126
# define ERR_EXECTUE_COMMAND_NOT_FOUND 127
# define ERR_EXECTUE_COMMAND_NO_FILE 128

/**
 * 에러를 g_exit_code 에 저장하고, 에러종류 에 따라서 메세지를 출력합니다.
 *
 * @param type 에러 종류
 * @param data 에러 종류에 따라 필요한 문자열
 * @return ERROR
 *
 * @note 에러 종류에 따라 data 에 들어가는 내용은 다음과 같습니다.
 * @e ERR_PARSE_SYNTAX : NULL
 * @e ERR_EXECUTE_REDIR_NO_FILE : 파일/디렉토리 이름
 * @e ERR_EXECTUE_COMMAND_IS_DIRECTORY : 명령어
 * @e ERR_EXECTUE_COMMAND_NOT_FOUND : 명령어
 * @e ERR_EXECTUE_COMMAND_NO_FILE : 명령어
 *
 * @throw 에러코드를 g_exit_code 에 담습니다.
 */
int		ft_error(int type, char *data);

/**
 * 에러 메세지를 출력합니다.
 *
 * @note ft_error 호출함
 */
void	ft_error_msg_syntax(void);
void	ft_error_msg_no_file(char *file);
void	ft_error_msg_command_not_found(char *command);
void	ft_error_msg_command_is_directory(char *command);

void	error_message_for_env(char *key);
void	error_message_for_unset(char *key, char *value);
void	error_message_for_export(char *argv);
void	error_message_for_exit(char *argv);

#endif
