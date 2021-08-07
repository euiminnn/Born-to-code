#include <stdio.h>

int main(void)
{
	int i = 0;
	int j = 0;
	int k = -1;
	int column = 5;
	while (i < column)
	{
		printf("i = %d\n", i);
		i++;
	}
	while (j++ < column)
		printf("j = %d\n", j);
	while (k++ < column)
		printf("k = %d\n", k);
	return (0);
}
