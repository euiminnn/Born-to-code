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
void	*portal;
int		heart;
void	*heart_r;
void	*heart_b;
void	*heart_p;

//Only param->x will be used.
void			param_init(t_param *param)
{
	param->x = 0;
	param->y = 0;
	param->str[0] = 'a';
	param->str[1] = 'b';
	param->str[2] = '\0';
}

int				key_press(int keycode)
{
	static int a = 0;
	int flag = 0;
/*
	void	*img_black;
	int		img_w;
	int		img_h;
*/
	if (keycode == KEY_W)//Action when W key pressed
	{
		printf("up key pressed\n");
		param.y -= 48;
		if (param.y == 96)
			flag = -2;
	}
	else if (keycode == KEY_S) //Action when S key pressed
	{
		printf("down key pressed\n");
		param.y += 48;
		if (param.y == 96)
			flag = 2;
	}
	else if (keycode == KEY_D)
	{
		printf("front key pressed\n");
		param.x += 48;
		if (param.x == 96)
			flag = 1;
	}
	else if (keycode == KEY_A)
	{
		printf("back key pressed\n");
		param.x -= 48;
		if (param.x == 96)
			flag = -1;
	}
	else if (keycode == KEY_ESC) //Quit the program when ESC key pressed
		exit(0);
	printf("x: %d\n", param.x);
	mlx_put_image_to_window(mlx, win, back, 0, 0);
	mlx_put_image_to_window(mlx, win, tree, 96, 96);
	if (heart == 1)
		mlx_put_image_to_window(mlx, win, heart_r, 96+48, 96+48*2);
	mlx_put_image_to_window(mlx, win, heart_b, 96+48*2, 96+48*2);
	mlx_put_image_to_window(mlx, win, heart_p, 480-48*2, 480-48*3);
	mlx_put_image_to_window(mlx, win, portal, 480-48*2, 480-48*2);
	//mlx_put_image_to_window(mlx, win, tree, 96+48, 96);
	//mlx_put_image_to_window(mlx, win, tree, 96+48*2, 96);
	//mlx_put_image_to_window(mlx, win, tree, 96+48*3, 96);
	//mlx_put_image_to_window(mlx, win, tree, 96+48*3, 96+48);
	//mlx_put_image_to_window(mlx, win, tree, 96+48*3, 96+48*2);
	if (param.x == 96 && param.y == 96 && (flag == 1 || flag == -1))
		param.x -= flag * 48;
	if (param.x == 96 && param.y == 96 && (flag == 2 || flag == -2))
		param.y -= flag / 2 * 48;
	if (param.x == 480-48*2 && param.y == 480-48*2)
		exit(0);
	if (param.x == 96+48 && param.y == 96+48*2)
		heart = 0;
	if ((param.x/48) % 2 == 0)
		mlx_put_image_to_window(mlx, win, img_w1, param.x, param.y);
	else
		mlx_put_image_to_window(mlx, win, img_w3, param.x, param.y);	
	return (0);
}


#define BUFFER_SIZE 1

static int	find_index(char *s, char c)
{
	int	index;

	index = 0;
	while (*s != '\0')
	{
		if (*s == c)
			return (index);
		s++;
		index++;
	}
	return (-1);
}

static int	save_line(char **str, char **line, int index)
{
	char	*temp;

	*line = ft_substr(*str, 0, index);
	temp = ft_substr(*str, index + 1, ft_strlen(*str) - index - 1);
	free(*str);
	*str = temp;
	return (1);
}

int			get_next_line(int fd, char **line)
{
	static char	*str;
	int			ret;
	int			i_nl;
	char		buff[BUFFER_SIZE + 1];

	if (fd < 0 || !line || BUFFER_SIZE < 1 || read(fd, buff, 0) < 0)
		return (-1);
	if (str && ((i_nl = find_index(str, '\n')) != -1))
		return (save_line(&str, line, i_nl));
	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = '\0';
		str = ft_strjoin_free(str ? str : ft_strdup(""), buff);
		if (((i_nl = find_index(str, '\n')) != -1))
			return (save_line(&str, line, i_nl));
	}
	if (str)
	{
		*line = ft_strdup(str);
		free(str);
		str = NULL;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}

int		count_gnl(char *filename)
{
	int		fd;
	int		row;
	int		check;
	char	*line;

	fd = open(filename, O_RDONLY);
	row = 0;

	while ((check = get_next_line(fd, &line)) > 0)
	{
		row++;
		free(line);
	}
	free(line);
	close(fd);
	return (row);
}

// input : file name
// output : array
char	**read(char *filename)
{
    int    	fd;
	char	*line;
	int		check;
	int		row;
	char	**arr;
	int		i;

	row = count_gnl(filename);
	arr = malloc(sizeof(char*) * row);
    fd = open(filename, O_RDONLY);

	i = 0;
	while ((check = get_next_line(fd, &line)) > 0)
	{
		arr[i] = line;
		i++;
	}
	free(line);
	close(fd);
	return (arr);
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
	back = mlx_xpm_file_to_image(mlx, "../textures/grass_n_flower-3840.xpm", &img_width, &img_height);
	tree = mlx_xpm_file_to_image(mlx, "../textures/tree_48.xpm", &img_width, &img_height);
	img_w1 = mlx_xpm_file_to_image(mlx, "../textures/mushroom_xpm/walk1.xpm", &img_width, &img_height);
	img_w3 = mlx_xpm_file_to_image(mlx, "../textures/mushroom_xpm/walk3.xpm", &img_width, &img_height);
	heart_r = mlx_xpm_file_to_image(mlx, "../textures/redheart_48_withmargin.xpm", &img_width, &img_height);
	heart_b = mlx_xpm_file_to_image(mlx, "../textures/blueheart_48_withmargin.xpm", &img_width, &img_height);
	heart_p = mlx_xpm_file_to_image(mlx, "../textures/purpleheart_48_withmargin.xpm", &img_width, &img_height);
	portal = mlx_xpm_file_to_image(mlx, "../textures/portal_48.xpm", &img_width, &img_height);

	mlx_put_image_to_window(mlx, win, back, 0, 0);
	mlx_put_image_to_window(mlx, win, tree, 96, 96);
	mlx_put_image_to_window(mlx, win, heart_r, 96+48, 96+48*2);
	mlx_put_image_to_window(mlx, win, heart_b, 96+48*2, 96+48*2);
	mlx_put_image_to_window(mlx, win, heart_p, 480-48*2, 480-48*3);
	mlx_put_image_to_window(mlx, win, portal, 480-48*2, 480-48*2);
	//mlx_put_image_to_window(mlx, win, tree, 96+48, 96);
	//mlx_put_image_to_window(mlx, win, tree, 96+48*2, 96);
	//mlx_put_image_to_window(mlx, win, tree, 96+48*3, 96);
	//mlx_put_image_to_window(mlx, win, tree, 96+48*3, 96+48);
	//mlx_put_image_to_window(mlx, win, tree, 96+48*3, 96+48*2);
	mlx_put_image_to_window(mlx, win, img_w1, 0, 0);
	heart = 1;	
	mlx_loop(mlx);
	free(arr);
}
