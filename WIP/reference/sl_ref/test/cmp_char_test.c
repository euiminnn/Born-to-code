#include <stdio.h>

int	check_flag(char c1, char c2)
{
	if (!c1 || !c2)
		return (-1);
	if (c1 == c2)
		return (1);
	else
		return (0);
}

int main(void)
{
	printf("1 means same, 0 means different\n");
	printf("result(a, b): %d\n", check_flag('a', 'b'));
	printf("result(a, a): %d\n", check_flag('a', 'a'));
	printf("result(a, ): %d\n", check_flag('a', 0));
	printf("result(a, ): %d\n", check_flag(0, 0));
	return (0);
}
