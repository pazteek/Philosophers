#include "philosophers.h"

static void* test(void *arg)
{:
printf("je suis un philosophers\n");
printf("tu es un philosophers\n");
return arg;
}

int main()
{
	t_philosopher	*philosophers;
	philosophers = malloc(sizeof(t_philosopher));
	pthread_mutex_init(&a, NULL);
	pthread_create(&philosophers[0].thread_id,NULL, test,NULL);
	printf("je suis un philosophers2\n");
	usleep(1000000);
	printf("tu es un philosophers2\n");
	return (0);
}
