#include <stdio.h>

void	to_char(int binary)
{
	char result;
	result = binary + '0';// - '0';
	printf("%c", result);
	printf("\n");
}

int main(void)
{
	int binary;

	binary = 3;
	binary = binary << 1;
	binary = binary >> 1;

	printf("---------------------------\n");
	printf("1 in char: ");
	to_char(1);
	printf("5 in char: ");
	to_char(5);
}
