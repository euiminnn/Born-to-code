#include <unistd.h>
#include <stdio.h>
#include <limits.h>

// pwd 와 동일

int main() {
   char cwd[PATH_MAX];

   if (getcwd(cwd, sizeof(cwd)) != NULL) {
       printf("Current working dir: %s\n", cwd);
   } else {
       perror("getcwd() error");
       return 1;
   }
   return 0;
}