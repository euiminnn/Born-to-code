/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc_ref.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 17:27:29 by echung            #+#    #+#             */
/*   Updated: 2021/01/23 17:45:21 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc_ref(size_t count, size_t size)
{
	void	*array;
	//req = count * size
	
	CHECK_MALLOC(array, count * size);
	//CHECK_PTR((array = malloc(count * size)))
	//CHECK_PTR_DEF(array, NULL)
	//if (!(array)) return NULL;
	ft_memset(array, 0, count * size);
	return (array);
}
