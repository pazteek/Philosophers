#include <stdio.h>
#include <pthread.h>
#include <sys/time.h>
#include <stdlib.h>
#include <unistd.h>

# define STR_DIED "died"
# define STR_EAT "is eating"
# define STR_SLEEP "is sleeping"
# define STR_THINK "is thinking"

typedef struct	s_philosopher
{
				int				num;
				int				etat;
				pthread_t		thread_id;
				pthread_mutex_t	fork[2];
				pthread_mutex_t	general;
}				t_philosopher;


typedef struct	s_all
{
	int				number_of_philosopher;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	t_philosopher	**philosophers;
	pthread_mutex_t	general;
}			t_all;
