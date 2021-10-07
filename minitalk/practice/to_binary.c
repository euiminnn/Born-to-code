#include <stdio.h>

void	to_binary(int i)
{
	int cal;

	cal = 1 << 7;		//1000 0000(2)
	while (cal)
	{
		if (cal & i)
		{
			cal = cal >> 1;
			printf("1");
		}
		else
		{
			cal = cal >> 1;
			printf("0");
		}
	}
	printf("\n");
}

int main(void)
{
	char character;

	character = 'A';
	/*
	printf("type c: %c\n", character);
	printf("type d: %d\n", character);
	printf("type u: %u\n", character);

	printf("1000 0000 = 128? %d\n", 1 << 6);
	printf("1000 0000 = 128? %d\n", 1 << 7);
*/
	printf("---------------------------\n");
	printf("1 in binary: ");
	to_binary(1);
	printf("5 in binary: ");
	to_binary(5);
}
