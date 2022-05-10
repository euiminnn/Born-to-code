/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 20:52:46 by ycha              #+#    #+#             */
/*   Updated: 2022/04/25 19:47:49 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

#define KEY_NUM 6

static void	parser_init(int (*parser[6])(char **))
{
	parser[a] = parse_a;
	parser[c] = parse_c;
	parser[l] = parse_l;
	parser[sp] = parse_sp;
	parser[pl] = parse_pl;
	parser[cy] = parse_cy;
}

static int	find_key_index(char *key)
{
	int	j;

	j = -1;
	while (++j < KEY_NUM)
	{
		if (ft_strncmp(key, (char [6][3]){
			"A", "C", "L", "sp", "pl", "cy"}[j]) == 0)
		{
			if (j == 0)
				m()->num_a++;
			if (j == 1)
				m()->num_c++;
			if (j == 2)
				m()->num_l++;
			break ;
		}
	}
	return (j);
}

static int	parsing(char *file_data)
{
	int		i;
	int		key_index;
	int		(*parser[6])(char **);
	char	**lines;
	char	**words;

	i = -1;
	parser_init(parser);
	lines = ft_split(file_data, "\n");
	while (lines[++i])
	{
		words = ft_split(lines[i], WHITESPACE);
		if (!words[0])
		{
			ft_free_split(words, ft_arrsize(words));
			continue ;
		}
		key_index = find_key_index(words[0]);
		if (key_index == KEY_NUM || !parser[key_index](words))
			return (free_line(lines, words));
		ft_free_split(words, ft_arrsize(words));
	}
	ft_free_split(lines, ft_arrsize(lines));
	return (OK);
}

static int	fileread(char *file_name, char *file_data)
{
	char	ch;
	int		len;
	int		fd;
	int		s;

	fd = open(file_name, O_RDONLY);
	len = ft_strlen(file_name);
	if (fd < 0
		|| len < 3
		|| file_name[len - 3] != '.'
		|| file_name[len - 2] != 'r'
		|| file_name[len - 1] != 't')
	{
		close(fd);
		return (ERROR);
	}
	s = read(fd, &ch, 1);
	while (s > 0)
	{
		*file_data++ = ch;
		s = read(fd, &ch, 1);
	}
	close(fd);
	return (s >= 0);
}

int	input(int argc, char **argv)
{
	char	file_data[MAX_FILE_READ];

	m()->num_a = 0;
	m()->num_c = 0;
	m()->num_l = 0;
	if (argc != 2 || !fileread(argv[1], file_data) || !parsing(file_data))
		return (ERROR);
	if (m()->num_a * m()->num_c * m()->num_l != 1)
		return (ERROR);
	return (OK);
}
