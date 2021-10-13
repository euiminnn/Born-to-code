#ifndef FT_LIST_H
# define FT_LIST_H

# include <stdio.h>
# include <stdlib.h>

typedef struct s_list
{
    void            *data;
    struct s_list   *next;
}   t_list;

/**
 * 연결 리스트를 초기화합니다.
 *
 * @return 리스트 주소 (free 필요)
 */
t_list  *init_list();

/**
 * 리스트의 마지막에 값을 추가합니다.
 *
 * @param list 리스트
 * @param data 값 (null 일 수 있다.)
 */
void    push_list(t_list *list, void *data);

/**
 * 리스트의 크기를 잽니다.
 * 
 * @param list 리스트
 * @return 리스트 크기
 */
int count_list(t_list *list);

/**
 * 리스트의 메모리를 해제합니다.
 *
 * @param list 리스트
 * @param del 삭제시 호출될 함수
 */
void    free_list(t_list *list, void (*del)(void *data));

#endif
