6th July

## minitalk 시작 !

- `void signal(int signalnum, void (*f)(int));`

- 사용 예시: `signal(SIGUSR1, handler);`

- getpid() : PID 리턴

- while문 실행 중에 ctrl+C 라는 시그널을 보내보자.

```c
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void handler(int num)
{
    write(1, "I won't die!\n", 13);
}

int main()
{
    signal(SIGINT, handler); //ctrl+C 실행시 handler함수 호출
    while (1)
    {
        printf("Wasting your time. %d\n", getpid());
        sleep(1);
    }
}
```
 
 ctrl+C 로도 프로그램 종료 불가해짐 -> 프로그램 종료하고 싶으면 다른 터미널 창에 `kill -TERM signalnum`


