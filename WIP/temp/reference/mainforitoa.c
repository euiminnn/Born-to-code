#include <stdio.h>
#include <stdlib.h>

char	*ft_itoa(int n);

int	main(void)
{
	int n = -2147483648;
	char	*myresult;

	myresult = ft_itoa(n);

	printf("main : %s", myresult);
}
