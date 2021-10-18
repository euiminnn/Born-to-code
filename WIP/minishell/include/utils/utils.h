#include "lib/libft.h"

#include "define.h"
#include <stdio.h>
#include <string.h>

void	ft_exit(int err);
char*	ft_strjoins(char **strs, int n);
char    **ft_free_strings(char **arr);
void    ft_free(void *data);
void    ft_close(int fd);
int     ft_dup(int fd1, int fd2);

/**
 * str 에서 첫번째 = 을 기준으로 key 와 value 를 가져옵니다.
 * 
 * @warning key 와 value 를 꼭 free 해주세요.
 * 
 * @param str 문자열
 * @param key key 문자열 포인터 (free 필요)
 * @param value value 문자열 포인터 (없을경우 NULL, free 필요)
 */
void     ft_get_key_value(char* str, char **key, char **value);
