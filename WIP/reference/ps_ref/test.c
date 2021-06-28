#include <stdio.h>
#include <unistd.h>

long long	ft_atoi(char *str)
{
	int	sign;
	long long	result;

	sign = 1;
	while (*str == ' ' || (9 <= *str && *str <= 13))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = sign * -1;
		str++;
		if (*str == '-' || *str == '+')
			return (0);
	}
	result = 0;
	while ('0' <= *str && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	result = sign * result;
	return (result);
}

int main(int argc, char **argv)
{
	int i = argc-1;
	while (i > 0)
	{
		if (ft_atoi(argv[i]) <= 2147483647 && ft_atoi(argv[i]) >= -2147483648)
		{
			printf("Ok\n");
		}
		else
			write(2, "Error\n", 6);
		i--;
	}
}
