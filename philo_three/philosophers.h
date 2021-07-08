#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>

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
	sem_t			*fork;
	pid_t			*thread_id;
	t_chrono		*chrono;
}				t_philosopher;

