#include <stdio.h>
#include <stdlib.h>


typedef struct s_env
{
    char *key;
    char *value;
    struct s_env *next;
}   t_env;


/**
 * t_env 구조체 만드는 함수!
 *
 * t_env malloc
 * key, value 집어넣고,
 * 일단 next 는 null 로....
 *
 */
t_env *make_env_node(char *key, char *value)
{

}

/**
 * t_end 구조체들로 만들어진 연결 리스트 만드는 함수!
 *
 * make_env_node 3번 호출해서 t_env 구조체 3개 만들기
 * t_env 구조체 next 변수들로 서로 연결하기!
 *
 *
 */
t_env *insert_to_struct(char *key, char *value)
{
    t_env   *node;

	node = (t_env *)malloc(sizeof(t_env));
	node->key = key;
	node->value = value;
	node->next = NULL;

    return (node);
}
/*
	int i;

	i = 3;
	while (i)
	{
		node->key = "키";
		node->value = "값";
		i--;
	}
*/



void	builtin_export_only(int argc, char **argv, t_env *env)
{
	t_env *node;

	node = env->next;
	while (node)
	{
		printf("declare -x ");
		printf("%s", node->key);
		printf("=");
		printf("\"");
		printf("%s", node->value);
		printf("\"\n");
		node = node->next;
	}
}

int main(int argc, char **argv, char **envp)
{
	t_env *env;

	env = init_env(envp);
	builtin_export_only(argc, argv, env);
}
