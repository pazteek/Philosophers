#include <stdio.h>
#include <pthread.h>
#include <sys/time.h>
#include <stdlib.h>
#include <unistd.h>

# define STR_TAKEN "has taken a fork"
# define STR_DIED "died"
# define STR_EAT "is eating"
# define STR_SLEEP "is sleeping"
# define STR_THINK "is thinking"

typedef struct	s_chrono
{
	int				number_of_philosopher;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_each;
	pthread_mutex_t	general;
}				t_chrono;

typedef struct	s_philosopher
{
	long long		time_to_live;
	long long		last_eat;
	int				num;
	int				etat;
	pthread_t		thread_id;
	pthread_mutex_t	fork[2];
	pthread_mutex_t	general;
	t_chrono		*chrono;
}				t_philosopher;

