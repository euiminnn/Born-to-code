#include <stdio.h>
int main(void)
{
	int i = 1;
	while (i < 4)
	{
		printf("first: %d\n", i);
		i++;
	}
	i = 0;
	while (++i < 4)
	{
		printf("second: %d\n", i);
	}
}
