/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:24:16 by echung            #+#    #+#             */
/*   Updated: 2021/10/21 17:39:20 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include <stdio.h>
# include <stdlib.h>

typedef struct s_list
{
	void			*data;
	struct s_list	*next;
}	t_list;

/**
 * 연결 리스트를 초기화합니다.
 *
 * @return 리스트 주소 (free 필요)
 */
t_list	*init_list(void);

/**
 * 리스트의 마지막에 값을 추가합니다.
 *
 * @param list 리스트
 * @param data 값 (null 일 수 있다.)
 */
void	push_list(t_list *list, void *data);

/**
 * 리스트의 크기를 잽니다.
 * 
 * @param list 리스트
 * @return 리스트 크기
 */
int		count_list(t_list *list);

/**
 * 리스트의 메모리를 해제합니다.
 *
 * @param list 리스트
 * @param del 삭제시 호출될 함수
 */
void	free_list(t_list *list, void (*del)(void *data));

/**
 * 연결 리스트를 주어진 함수를 통하여 문자열로 바꿉니다.
 * 
 * @param env 환경 변수 구조체
 * @param to_string 주어진 data 를 알맞는 문자열로 변환해주는 함수 (NULL 반환시 건너뜀)
 * @return 이차원 문자열 (free 필요)
 */
char	**to_string_list(t_list *list, char *(*to_string)(void *data));

#endif
