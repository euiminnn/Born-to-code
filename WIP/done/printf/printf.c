#include <stdio.h>
int main(void)
{
	char *ptr;
	char *str;
	/*
	str = "this is string";
	printf("percent: %%\n");
	printf(".p: %.p\n", ptr);
	printf("s: %s\n", str);
	printf("55p: %55p\n", ptr);
	*/
	printf(".5d, 123: %.5d\n", 123);
	printf("05d, 123: %05d\n", 123);
	printf("05d, -123: %05d\n", -123);
	printf("-05d, -123: %-05d\n", -123);
	printf("-05d, 123: %-05d\n", 123);
	printf("-5d, 123: %-5d\n", 123);
	printf("-5d, -123: %-5d\n", -123);
	/*
	printf("i: %i\n", -20);
	printf("u: %u\n", 10);
	printf("x: %x\n", 123);
	printf("X: %X\n", 0XF1);
	*/
	return (0);
}
