/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 20:28:30 by echung            #+#    #+#             */
/*   Updated: 2021/10/28 14:23:12 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_global	g;
	char		*map;

	map = argv[1];
	if (argc != 2 || !is_valid_file_type(map, ".ber"))
	{
		printf("Error\n");
		return (0);
	}
	ft_bzero(&g, sizeof(g));
	if (!init_game(map, &g) || !is_valid_map(&g))
		printf("Error\n");
	free_all(g.arr, g.row);
	return (0);
}
