#include <stdio.h>
#include <limits.h>
#include <unistd.h>	// chdir header

int main(void)
{
	char buffer[PATH_MAX] = { 0, };
	char changeDir[PATH_MAX] = { "/Users" }; // 절대 경로
    char changeDir[PATH_MAX] = { ".." }; // 상대 경로

	int result = chdir(changeDir);

	if(result == 0)
		printf("Success\n");
	else
		perror("Fail...\n");

	return 0;
}