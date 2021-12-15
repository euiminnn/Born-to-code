#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int ac, char **av, char **en) {
  pid_t pid;
  int status,i;

  pid = fork();

  if (pid > 0)
	  {
		pid_t waitpid;
		printf("부모 PID : %d\n", getpid());
		waitpid = wait(&status); // 자식 프로세스의 상태를 받아올 때까지 wait!
		if (waitpid == -1)
			printf("error\n");
		else
		{
			printf("status : %d\n", status & 255);
			if (WIFEXITED(status))
				printf("자식 프로세스 정상 종료 %d\n", status >> 8);
			else if (WIFSIGNALED(status))
				printf("자식 프로세스 비정상 종료: %d %d\n", WTERMSIG(status), status >> 8);
                // 비정상종료: kill 등으로 종료
                // $? 에 들어갈 내용 WTERMSIG(status)
		}
	}
  else if (pid == 0){  // 자식 프로세스
      printf("자식 PID : %ld \n",(long)getpid());
			execve("/bin/cat", av, en);
			// exit(100);
	}
  else {  // fork 실패
      perror("fork Fail! \n");
      return (-1);
  }

  return (0);
}
