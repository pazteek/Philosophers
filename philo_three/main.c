#include "philosophers.h"

static void			talk_philo(long time, int num, char *etat, t_chrono *chrono)
{
	pthread_mutex_lock(&chrono->general);
	printf("%ld %d %s\n", time, num, etat);
	if (etat != STR_DIED)
		pthread_mutex_unlock(&chrono->general);
}

static long long	ft_time(void)
{
	struct timeval	time1;
	long long		time;

	gettimeofday(&time1, DST_NONE);
	time = time1.tv_usec;
	time += time1.tv_sec * 1000000;
	return (time);
}

static long			ft_test_to_live(t_philosopher *philo, char *etat)
{
	long long	time;

	time = ft_time() - philo->time_to_live;
	if (etat == STR_EAT)
		philo->last_eat = time;
	if (philo->chrono->time_to_die < (time - philo->last_eat) / 1000)
	{
		talk_philo(time / 1000, philo->num + 1, STR_DIED, philo->chrono);
		exit(1);
	}
	talk_philo(time / 1000, philo->num + 1, etat, philo->chrono);
	return (time);
}

static void			*test(void *arg)
{
	long			time;
	t_philosopher	*philo;

	philo = (t_philosopher*)arg;
	philo->time_to_live = ft_time();
	philo->last_eat = 0;
	while (1)
	{
		ft_test_to_live(philo, STR_THINK);
		sem_wait(philo->fork);
		ft_test_to_live(philo, STR_TAKEN);
		sem_wait(philo->fork);
		ft_test_to_live(philo, STR_TAKEN);
		ft_test_to_live(philo, STR_EAT);
		usleep(philo->chrono->time_to_eat * 1000);
		sem_post(philo->fork);
		sem_post(philo->fork);
		ft_test_to_live(philo, STR_SLEEP);
		usleep(philo->chrono->time_to_sleep * 1000);
	}
	return (arg);
}

void				initialization_fork(int number_of_philosopher,
									t_philosopher *philosophers)
{
	int				i;
	sem_t			*fork;

	i = -1;
	while (++i < number_of_philosopher)
		fork = sem_open("frock",O_CREAT, NULL, number_of_philosopher);
	i = -1;
	while (++i < number_of_philosopher)
	{
		philosophers[i].num = i;
		philosophers[i].fork = fork;
	}
}

void				initialization_pthread(int number_of_philosopher,
						t_philosopher *philosophers)
{
	int	i;
	pid_t	pid;

	i = -1;
	pid = 0;
	while (++i < number_of_philosopher)
	{
		if (pid != 0|| i == 0)
			pid = fork();
		if ( pid != 0)
			philosophers[i].thread_id = &pid;
		if (pid == 0)
			test(&philosophers[i]);
	}
}

void				initialization_philosophers(int number_of_philosopher,
		t_chrono *all, t_philosopher *philosophers)
{
	int	i;

	i = -1;
	while (++i < all->number_of_philosopher)
		philosophers[i].chrono = all;
}

int					main(int argv, char **argc)
{
	t_chrono			all;
	t_philosopher		*philosophers;
	pthread_mutex_t		*fork;
	int					i;

	i = -1;
	all.number_of_philosopher = atoi(argc[1]);
	all.time_to_die = atoi(argc[2]);
	all.time_to_eat = atoi(argc[3]);
	all.time_to_sleep = atoi(argc[4]);
	if (argv == 6)
		all.number_of_each = atoi(argc[5]);
	philosophers = malloc(sizeof(t_philosopher) * all.number_of_philosopher);
	initialization_philosophers(all.number_of_philosopher, &all,
			philosophers);
	initialization_fork(all.number_of_philosopher, philosophers);
	initialization_pthread(all.number_of_philosopher, philosophers);
	while (1)
		;
	return (0);
}
