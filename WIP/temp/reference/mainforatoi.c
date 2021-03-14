#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(char *str);

int	main(void)
{
	char *str = " -a123abc";
	int result;
	int myresult;

	result = atoi(str);
	myresult = ft_atoi(str);

	printf("%d : %d", result, myresult);

}
