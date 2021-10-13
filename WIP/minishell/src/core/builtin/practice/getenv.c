#include <stdio.h>
#include <stdlib.h>

int main () {
   printf("PATH : %s\n", getenv("PATH"));
   printf("HOME : %s\n", getenv("HOME"));
   printf("TERM : %s\n", getenv("TERM"));

   return(0);
}
