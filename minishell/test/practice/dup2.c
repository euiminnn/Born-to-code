#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>    //header file
#include <fcntl.h>

int main(void)
{
	int fd;

	if ((fd = open("file.txt", O_WRONLY | O_TRUNC | O_CREAT, 777)) < 0){
			printf("file open error\n");
			exit(0);
	}

	printf("이제 어디로 출력 될까?\n");

	/* 표준 출력을 file.txt 파일로 redirection 함 */ 
	dup2(fd, 1); 

	/* 표준 오류를 file.txt 파일로 redirection 함 */
	dup2(fd, 2);

	printf("여기로 왔어요!\n");

	close(fd);


	return (1);
}