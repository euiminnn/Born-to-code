/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordslen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 18:01:52 by echung            #+#    #+#             */
/*   Updated: 2021/01/27 15:45:59 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
size_t	ft_wordslen(char const *s, char c, size_t index)
{
	size_t	len;
	size_t	i;

	len = 0;
	i = -1;
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s != c && *s != '\0')
		{
			i = i + 1;
			if (i == index)
			{
				while (*s != c && *s != '\0')
				{
					len++;
					s++;
				}
			}
		}
		while (*s != c && *s != '\0')
			s++;
	}
	return (len);
}
#include <stdio.h>
int main(void)
{
	int len;
	char	c;
	c = 'c';
	len =	ft_wordslen("asscddc", c, 0);
	printf("len : %d", len);
	return(0);
}
