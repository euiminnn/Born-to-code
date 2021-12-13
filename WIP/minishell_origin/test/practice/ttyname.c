#include <stdio.h>
#include <termcap.h>

int main()
{
	char *env = getenv("TERM"); //TERM 설정을 가져옴
	if (env == NULL)
		env = "xterm"; //대부분 기본값은 xterm

	tgetent(NULL, env);                // xterm 설정을 사용하도록 초기화
	char *cm = tgetstr("cm", NULL);    // cursor motion
	char *ce = tgetstr("ce", NULL);    // 현재 커서 위치에서 한 줄의 끝까지 지우기
}