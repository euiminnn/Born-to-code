/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 17:03:09 by echung            #+#    #+#             */
/*   Updated: 2021/02/02 23:52:27 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*pnew;
	t_list	new;

	new.content = content;
	new.next = NULL;
	pnew = malloc(sizeof(t_list));
	if (!(pnew))
		return (0);
	*pnew = new;
	return (pnew);
}
