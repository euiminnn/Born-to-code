#include <stdio.h>
int main(void)
{
	char *ptr;
	char *str;
	str = "this is string";
	printf("percent: %%\n");
	printf("c: %c\n", 'a');
	printf("s: %s\n", str);
	printf("p: %p\n", ptr);
	printf("d: %d\n", 123);
	printf("i: %i\n", -20);
	printf("u: %u\n", 10);
	printf("x: %x\n", 123);
	printf("X: %X\n", 0XF1);
	return (0);
}
