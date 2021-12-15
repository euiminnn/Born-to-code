#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int ac, char **av, char **en) {
  pid_t waitpid;
  int status;

  if (fork() == 0)
  {
	  printf("자식 1 PID : %ld \n",(long)getpid());
	  sleep(2);
	  printf("자식 1 끝\n");
	  exit(0);
  }

  if (fork() == 0)
  {
	  printf("자식 2 PID : %ld \n",(long)getpid());
	  sleep(4);
	  printf("자식 2 끝\n");
	  exit(0);
  }


  waitpid = wait(&status);
  printf("waited : %d\n", waitpid);

  waitpid = wait(&status);
  printf("waited : %d\n", waitpid);

  waitpid = wait(&status);
  printf("waited : %d\n", waitpid);
  
  return (0);
}
