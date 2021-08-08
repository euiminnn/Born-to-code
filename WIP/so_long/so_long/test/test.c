#include <stdio.h>
int	is_instring(int c, char *s)
{
	if (c == '\0')
		return (0);
	while (*s != '\0')
	{
		if (c == *s)
			return (1);
		s++;
	}
	return (0);
}

int main(void)
{
	if (is_instring('a', "abc"))
		printf("Great!\n");
	return (0);
}
