#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	g_count = 0;

void	*t_function(void *data)
{
	int	i;
	char *thread_name = (char *)data;
	g_count = 0;
	i = 0;
	//for (i = 0; i < 3; i++)
	while (i < 3)
	{
		printf("%s COUNT %d\n", thread_name, g_count);
		g_count++;
		i++;
		sleep(1);
	}
	return (NULL);
}

int	main(void)
{
	pthread_t	p_thread1;
	pthread_t	p_thread2;
	int			status;

	pthread_create(&p_thread1, NULL, t_function, (void *)"Thread1");
	pthread_create(&p_thread2, NULL, t_function, (void *)"Thread2");

	pthread_join(p_thread1, (void *)&status);
	pthread_join(p_thread2, (void *)&status);
}
