#include "../mlx/mlx.h"

#include <stdio.h>
#include <stdlib.h>
#include "../mlx/mlx.h"

#define X_EVENT_KEY_PRESS		2
#define X_EVENT_KEY_release		3
#define X_EVENT_KEY_EXIT		17 //exit key code

//Mac key code example
//All the key code example other than below is described on the site linked in READEME.md
#define KEY_ESC			53
# define KEY_Q			12
# define KEY_W			13
# define KEY_E			14
# define KEY_R			15
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

//Since key_press() can recieve only one argument, all the argument shold be gathered in one structure
//x,y and str are meaningless variables.
typedef struct s_param{
	int		x;
	int		y;
	char	str[3];
}				t_param;


void	*mlx;
void	*win;
t_param	param;
void	*img_w1;
void	*img_w3;
void	*back;
void	*tree;

//Only param->x will be used.
void			param_init(t_param *param)
{
	param->x = 3;
	param->y = 4;
	param->str[0] = 'a';
	param->str[1] = 'b';
	param->str[2] = '\0';
}

int				key_press(int keycode)
{
	static int a = 0;
/*
	void	*img_black;
	int		img_w;
	int		img_h;
*/
	if (keycode == KEY_W)//Action when W key pressed
	{
		printf("up key pressed\n");
		param.y -= 48;
	}
	else if (keycode == KEY_S) //Action when S key pressed
	{
		printf("down key pressed\n");
		param.y += 48;
	}
	else if (keycode == KEY_D)
	{
		printf("front key pressed\n");
		param.x += 48;
	}
	else if (keycode == KEY_A)
	{
		printf("back key pressed\n");
		param.x -= 48;
	}
	else if (keycode == KEY_ESC) //Quit the program when ESC key pressed
		exit(0);
	printf("x: %d\n", param.x);
	mlx_put_image_to_window(mlx, win, back, 0, 0);
	mlx_put_image_to_window(mlx, win, tree, 96, 96);
	mlx_put_image_to_window(mlx, win, tree, 96+48, 96);
	mlx_put_image_to_window(mlx, win, tree, 96+48*2, 96);
	mlx_put_image_to_window(mlx, win, tree, 96+48*3, 96);
	mlx_put_image_to_window(mlx, win, tree, 96+48*3, 96+48);
	mlx_put_image_to_window(mlx, win, tree, 96+48*3, 96+48*2);
	if ((param.x/48) % 2 == 0)
		mlx_put_image_to_window(mlx, win, img_w1, param.x, param.y);
	else
		mlx_put_image_to_window(mlx, win, img_w3, param.x, param.y);
		
	return (0);
}

int		main(void)
{
	int		img_width;
	int 	img_height;

	//initiation
	mlx = mlx_init();
	param_init(&param);

	//open window
	win = mlx_new_window(mlx, 480, 480, "mushroom");
	
	//key press
	mlx_hook(win, X_EVENT_KEY_PRESS, 0, &key_press, 0);

	//add image
	//back = mlx_new_image(mlx, 300, 300);
	back = mlx_xpm_file_to_image(mlx, "../textures/grass_n_flower-480.xpm", &img_width, &img_height);
	tree = mlx_xpm_file_to_image(mlx, "../textures/tree_48.xpm", &img_width, &img_height);
	img_w1 = mlx_xpm_file_to_image(mlx, "../textures/mushroom_xpm/walk1.xpm", &img_width, &img_height);
	img_w3 = mlx_xpm_file_to_image(mlx, "../textures/mushroom_xpm/walk3.xpm", &img_width, &img_height);

	mlx_put_image_to_window(mlx, win, back, 0, 0);
	mlx_put_image_to_window(mlx, win, tree, 96, 96);
	mlx_put_image_to_window(mlx, win, tree, 96+48, 96);
	mlx_put_image_to_window(mlx, win, tree, 96+48*2, 96);
	mlx_put_image_to_window(mlx, win, tree, 96+48*3, 96);
	mlx_put_image_to_window(mlx, win, tree, 96+48*3, 96+48);
	mlx_put_image_to_window(mlx, win, tree, 96+48*3, 96+48*2);
	mlx_put_image_to_window(mlx, win, img_w1, 0, 0);
	
	mlx_loop(mlx);
}
