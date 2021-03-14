/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_startidx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 18:01:52 by echung            #+#    #+#             */
/*   Updated: 2021/01/27 16:27:22 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
size_t	ft_startidx(char const *s, char c, size_t index)
{
	size_t	start;
	size_t	i;

	start = 0;
	i = -1;
	while (*s != '\0')
	{
		while (*s == c)
		{	
			s++;
			start++;
		}
		if (*s != c && *s != '\0')
		{
			i = i + 1;
			if (i == index)
			{
				return (start);
			}
		}
		while (*s != c && *s != '\0')
		{	
			s++;
			start++;
		}
	}
	return (0);
}
#include <stdio.h>
int main(void)
{
	int start;
	char	c;
	c = ' ';
	start =	ft_startidx("     this    is   split  ccasscddc  ", c, 1);
	printf("start : %d", start);
	return(0);
}
