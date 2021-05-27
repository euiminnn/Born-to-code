/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 22:59:07 by echung            #+#    #+#             */
/*   Updated: 2021/05/27 23:33:31 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	//write(1, argv[0], 1); -> .
	int	i;
	int j;

	i = 1;
	j = 0;
	
	char arr[10];
	//printf("%d", argc);
	
	while (i < argc)
	{
		arr[j] = *argv[i];
		i++;
		j++;
	}
	for(i = 0; i < 3; i++)
		printf("arr[i]=%d: %c\n", i, arr[i]);
}
