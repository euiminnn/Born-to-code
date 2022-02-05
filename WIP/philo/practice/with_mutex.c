#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

pthread_mutex_t mutex_lock;

int g_count = 0;

void	*t_function(void *data)
{
	int		i;
	char	*thread_name = (char *)data;

	pthread_mutex_lock(&mutex_lock);

	g_count = 0;
	i = 0;
	while (i < 3)
	{
		printf("%s COUNT %d\n", thread_name, i);
		g_count++;
		i++;
		sleep(1);
	}
	pthread_mutex_unlock(&mutex_lock);
	return (NULL);
}

#include <errno.h>
int	main(void)
{
	pthread_t	p_thread1;
	pthread_t	p_thread2;
	int	status;

	pthread_mutex_init(&mutex_lock, NULL);

	pthread_create(&p_thread2, NULL, t_function, (void *)"Thread1");
	pthread_create(&p_thread1, NULL, t_function, (void *)"Thread2");

	int a = pthread_join(p_thread2, (void *)&status);
	int b = pthread_join(p_thread1, (void *)&status);
}
