#include "so_long.h"
#include "../mlx/mlx.h"

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../mlx/mlx.h"

#define X_EVENT_KEY_PRESS		2
#define X_EVENT_KEY_release		3
#define X_EVENT_KEY_EXIT		17 //exit key code

//Mac key code example
//All the key code example other than below is described on the site linked in READEME.md
#define KEY_ESC			53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

//Since key_press() can recieve only one argument, all the argument shold be gathered in one structure
//x,y and str are meaningless variables.

void	*mlx;
void	*win;
t_param	param;
void	*img_w1;
void	*img_w3;
void	*back;
void	*tree;
void	*portal;
void	*heart_r;
void	*heart_b;
void	*heart_p;
char	**arr;
int		start_x;
int		start_y;
int		row;
int		column;
int		count_heart;
int		collectibles;

//Only param->x will be used.
void			param_init(t_param *param)
{
	param->x = start_x;
	param->y = start_y;
	param->str[0] = 'a';
	param->str[1] = 'b';
	param->str[2] = '\0';
}

int				key_press(int keycode)
{
	static int a = 0;
	int flag = 0;

	if (keycode == KEY_W)//Action when W key pressed
	{
		printf("up key pressed\n");
		param.y -= 48;
		printf("param.y: %d, param.x: %d\n", param.y, param.x);
		if (arr[param.y/48][param.x/48] == '1')
			param.y += 48;
	}
	else if (keycode == KEY_S) //Action when S key pressed
	{
		printf("down key pressed\n");
		param.y += 48;
		if (arr[param.y/48][param.x/48] == '1')
			param.y -= 48;
	}
	else if (keycode == KEY_D)
	{
		printf("front key pressed\n");
		param.x += 48;
		if (arr[param.y/48][param.x/48] == '1')
			param.x -= 48;
	}
	else if (keycode == KEY_A)
	{
		printf("back key pressed\n");
		param.x -= 48;
		if (arr[param.y/48][param.x/48] == '1')
			param.x += 48;
	}
	else if (keycode == KEY_ESC) //Quit the program when ESC key pressed
	{
		free(arr);
		exit(0);
	}
	printf("x: %d\n", param.x);


	if (arr[param.y/48][param.x/48] == 'C')
	{
		count_heart++;
		arr[param.y/48][param.x/48] = '0';
	}
	if (arr[param.y/48][param.x/48] == 'E' && count_heart == collectibles)
	{
		free(arr);
		exit(0);
	}
	mlx_put_image_to_window(mlx, win, back, 0, 0);

	row = count_gnl("map.ber");
	column = ft_strlen(arr[0]);
	int i = 0;
	int j = 0;

// MAP
	while (i < row)
	{
		j = 0;
		while (j < column)
		{
			if (arr[i][j] == '1')
				mlx_put_image_to_window(mlx, win, tree, 48*j, 48*i);
			if (arr[i][j] == 'C')
				mlx_put_image_to_window(mlx, win, heart_r, 48*j, 48*i);
			if (arr[i][j] == 'E')
				mlx_put_image_to_window(mlx, win, portal, 48*j, 48*i);
			j++;
		}
		i++;
	}

	if ((param.x/48) % 2 == 0)
		mlx_put_image_to_window(mlx, win, img_w1, param.x, param.y);
	else
		mlx_put_image_to_window(mlx, win, img_w3, param.x, param.y);	
	return (0);
}

void	init_map(void)
{
	int i;
	int j;
	
	mlx_put_image_to_window(mlx, win, back, 0, 0);
	i = -1;
	while (i++ < row-1)
	{
		j = -1;
		while (j++ < column-1)
		{
			if (arr[i][j] == '1')
				mlx_put_image_to_window(mlx, win, tree, 48*j, 48*i);
			if (arr[i][j] == 'C')
			{
				mlx_put_image_to_window(mlx, win, heart_r, 48*j, 48*i);
				collectibles += 1;
			}
			if (arr[i][j] == 'E')
				mlx_put_image_to_window(mlx, win, portal, 48*j, 48*i);
			if (arr[i][j] == 'P')
			{
				mlx_put_image_to_window(mlx, win, img_w1, 48*j, 48*i);
				start_x = 48*j;
				start_y = 48*i;
			}
		}
	}
}

void	get_image(void)
{
	int		img_width;
	int 	img_height;

	back = mlx_xpm_file_to_image(mlx, "../textures/grass_n_flower-3840.xpm", &img_width, &img_height);
	tree = mlx_xpm_file_to_image(mlx, "../textures/tree_48.xpm", &img_width, &img_height);
	img_w1 = mlx_xpm_file_to_image(mlx, "../textures/mushroom_xpm/walk1.xpm", &img_width, &img_height);
	img_w3 = mlx_xpm_file_to_image(mlx, "../textures/mushroom_xpm/walk3.xpm", &img_width, &img_height);
	heart_r = mlx_xpm_file_to_image(mlx, "../textures/redheart_48_withmargin.xpm", &img_width, &img_height);
	heart_b = mlx_xpm_file_to_image(mlx, "../textures/blueheart_48_withmargin.xpm", &img_width, &img_height);
	heart_p = mlx_xpm_file_to_image(mlx, "../textures/purpleheart_48_withmargin.xpm", &img_width, &img_height);
	portal = mlx_xpm_file_to_image(mlx, "../textures/portal_48.xpm", &img_width, &img_height);
}

int		main(void)
{

	//initiation
	mlx = mlx_init();

	//open window
	win = mlx_new_window(mlx, 480, 480, "mushroom");
	
	//key press
	mlx_hook(win, X_EVENT_KEY_PRESS, 0, &key_press, 0);

	//add image
	get_image();

	arr = readfile("map.ber");
	row = count_gnl("map.ber");
	column = ft_strlen(arr[0]);

	init_map();
	param_init(&param);
	if (parse_map(arr, row, column))
		mlx_loop(mlx);
	else
		printf("🚫 Error: invalid map\n");
	free(arr);
}
