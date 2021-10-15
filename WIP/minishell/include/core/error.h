#ifndef FT_ERROR_H
# define FT_ERROR_H

# include <stdio.h>

# include "define.h"

# define ERR_PARSE_SYNTAX 2
# define ERR_PARSE_MULTI_LINE 42
# define ERR_EXECUTE_NO_FILE 1
# define ERR_EXECTUE_NOT_COMMAND 127

/**
 * 에러를 errno 에 저장하고, 에러종류 에 따라서 메세지를 출력합니다.
 *
 * @param type 에러 종류
 * @param data 에러 종류에 따라 필요한 문자열
 * @return ERROR
 *
 * @note ERR_PARSE_SYNTAX : NULL
 * @note ERR_PARSE_MULTI_LINE : NULL
 * @note ERR_EXECUTE_NO_FILE : 파일/디렉토리 이름
 * @note ERR_EXECTUE_NOT_COMMAND : 명령어
 *
 * @throw 에러코드를 errno 에 담습니다.
 */
int	ft_error(int type, char *data);

/**
 * 에러 메세지를 출력합니다.
 *
 * @note ft_error 호출함
 */
void	ft_error_msg_multi_line();
void	ft_error_msg_syntax();
void	ft_error_msg_no_file(char *file);
void	ft_error_msg_not_command(char *command);

#endif
