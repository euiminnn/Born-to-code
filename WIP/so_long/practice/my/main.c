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

//Only param->x will be used.
void			param_init(t_param *param)
{
	param->x = 3;
	param->y = 4;
	param->str[0] = 'a';
	param->str[1] = 'b';
	param->str[2] = '\0';
}

int				key_press(int keycode, t_param *param)
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
		param->x++;
	}
	else if (keycode == KEY_S) //Action when S key pressed
	{
		printf("down key pressed\n");
/*
		img_black = mlx_xpm_file_to_image(mlx, "../textures/black_window.xpm", &img_w, &img_h);
		mlx_put_image_to_window(mlx, win, img, 200, 200);	// ?????should i send win?????
*/
		param->x--;
	}
	else if (keycode == KEY_ESC) //Quit the program when ESC key pressed
		exit(0);
	printf("x: %d\n", param->x);
	return (0);
}

int		main(void)
{
	void	*mlx;
	void	*win;
	t_param	param;
	void	*img;
	void	*img_h1;
	void	*img_h2;

	int		img_width;
	int 	img_height;

	//initiation
	mlx = mlx_init();

	//open window
	win = mlx_new_window(mlx, 800, 800, "purple_quack");
	
	//key press
	param_init(&param);
	mlx_hook(win, X_EVENT_KEY_PRESS, 0, &key_press, &param);

	//add image
	img = mlx_xpm_file_to_image(mlx, "../textures/pduck-cutout.xpm", &img_width, &img_height);
	img_h1 = mlx_xpm_file_to_image(mlx, "../textures/pduck_hurt1-cutout.xpm", &img_width, &img_height);
	img_h2 = mlx_xpm_file_to_image(mlx, "../textures/pduck_hurt2-cutout.xpm", &img_width, &img_height);
	//mlx_put_image_to_window(mlx, win, img, 5, 5);
	mlx_put_image_to_window(mlx, win, img_h1, 200, 200);
	//mlx_put_image_to_window(mlx, win, img_h2, 400, 400);
	
	mlx_loop(mlx);
}
