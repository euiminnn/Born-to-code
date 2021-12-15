#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int	basic()
{
    int x;

    x = 0;
    fork();
    x = 1;
    printf("PID : %d, x : %d\n", getpid(), x);
    return (0);
}

int	parent_child()
{
    pid_t pid = 123;

	pid = fork();

	if (pid > 0)  // 부모 코드
		printf("부모 프로세스 입니다. pid : %d\n", pid);
	else // 자식 코드
		printf("자식 프로세스 입니다. pid : %d\n", pid);

	return (0);
}

int main(void)
{
    parent_child();
    return (0);
}