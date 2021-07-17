#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void handler(int num)
{
    write(1, "I won't die!\n", 13);
}

int main()
{
    signal(SIGINT, handler);
    while (1)
    {
        printf("Wasting your time. %d\n", getpid());
        sleep(1);
    }
}
