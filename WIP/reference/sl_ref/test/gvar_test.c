#include <stdio.h>

typedef struct s_param {
	int x;
}	t_param;

typedef struct s_global {
	int global;
	t_param param;
}	t_global;

void	func2(t_global *g)
{
	(g->global)++;
	printf("global3 = %d\n", g->global);
}
void	func1(t_global *g)
{
	(g->global)++;
	printf("global2 = %d\n", g->global);
}
void	func(t_global *g)
{
	(g->global)++;
	printf("global1 = %d\n", g->global);
	printf("param.x = %d\n", g->param.x);
}


int main(void)
{
	t_global g;

	g.global = 0;
	g.param.x = 0;
	func(&g);
	func1(&g);
	func2(&g);
}
