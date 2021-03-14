/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 18:01:52 by echung            #+#    #+#             */
/*   Updated: 2021/01/27 15:27:35 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	ft_countwords(char const *s, char c)
{
	int	count;
	int i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
			count++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (count);
}
#include <stdio.h>
int main(void)
{
	int count;
	char	c;
	c = 'c';
	count =	ft_countwords("asscddc", c);
	printf("%d", count);
	return(0);
}
