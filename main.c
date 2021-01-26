#include "philosophers.h"

static void talk_philo(int num, char *etat)
{
	int	time;
	time = 0;
	printf("%d %d %s\n", time ,num, etat);
}

static void* test(void *arg)
{
	struct timeval time1;
	struct timeval time2;
	t_philosopher *philo;
	philo = (t_philosopher*)arg;
	while (1)
	{
	gettimeofday(&time1, DST_NONE);
	pthread_mutex_lock(&philo->fork[0]);
	pthread_mutex_lock(&philo->fork[1]);
	talk_philo(philo->num, STR_EAT);
	usleep(100);
	pthread_mutex_unlock(&philo->fork[0]);
	pthread_mutex_unlock(&philo->fork[1]);
	talk_philo(philo->num, STR_SLEEP);
	usleep(100);
	talk_philo(philo->num, STR_THINK);
	printf("je suis un philosophers\n");
	usleep(100);
	printf("tu es un philosophers\n");
	pthread_mutex_unlock(arg);
	}
return arg;
}
void initialization_fork(int number_of_philosopher, t_philosopher* philosophers)
{
	int	i;
	pthread_mutex_t			*fork;

	fork = malloc(sizeof(pthread_mutex_t) * number_of_philosopher);
	i = -1;
	while (++i < number_of_philosopher)
		pthread_mutex_init(&fork[i], NULL);
	i = -1;
	while (++i < number_of_philosopher)
	{
		philosophers[i].num = 1;
		philosophers[i].fork[0] = fork[i];
		philosophers[i].fork[1] = fork[(i + 1)%number_of_philosopher];
	}
}

void	initialization_pthread(int number_of_philosopher, t_philosopher* philosophers)
{
	int	i;

	i = -1;
	while (++i < number_of_philosopher)
		pthread_create(&philosophers[i].thread_id,NULL, test, philosophers[0].fork);
}

void	initialization_philosophers(int number_of_philosopher, t_all* all,
						t_philosopher* philosophers, pthread_mutex_t *general)
{
	int i;

	i = -1;
	all->general = *general;
	all->philosophers = malloc(sizeof(t_philosopher*)* number_of_philosopher);
	while (++i < number_of_philosopher)
		all->philosophers[i] = &philosophers[i];
}

int	main()
{
	t_all			all;
	t_philosopher	*philosophers;
	pthread_mutex_t	*fork;
	pthread_mutex_t	general;
	int				i;

	i = -1;
	all.number_of_philosopher = 2;
	philosophers = malloc(sizeof(t_philosopher) * all.number_of_philosopher);
	pthread_mutex_init(&general, NULL);
	while (++i < all.number_of_philosopher)
		philosophers[i].general = general;
	pthread_mutex_lock(&general);
	initialization_philosophers(all.number_of_philosopher, &all, philosophers, &general);
	initialization_fork(all.number_of_philosopher, philosophers);
	initialization_pthread(all.number_of_philosopher, philosophers);
	pthread_mutex_lock(&general);
	return (0);
}
