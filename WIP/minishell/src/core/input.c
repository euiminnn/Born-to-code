#include "minishell.h"

/**
 * 쉘을 입력 받습니다.
 *
 * @param line 입력받은 문자열 저장할 주소
 * @return 성공하면 OK 실패하면 ERROR
 */
int	input(char **line)
{
    char *str;

	str = readline("의민쉘$ ");
	if (str)
		*line = str;
	else
		return (ERROR);
	add_history(str);
    return(OK);
}
