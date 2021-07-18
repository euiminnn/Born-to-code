#include <stdio.h>
#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int main(void)
{
	int binary;
	int i;

	binary = 0;
	i = 0;

	while (i < 8)
	{
		if (i % 2 == 0)
		{
			binary = binary << 1;
			binary += 1;
		}
		else
			binary = binary << 1;
		i++;
	}
	binary = binary << 1;
	
	char result;
	result = binary + '0' - '0';
	write(1, "binary to char = ", 16);
	ft_putchar_fd(result, 1);
	write(1, "\n", 1);
}
