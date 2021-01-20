#include <stdio.h>
#include <pthread.h>
#include <sys/time.h>
#include <stdlib.h>
#include <unistd.h>


typedef struct	s_philosopher
{
				int etat;
				pthread_t thread_id;
				pthread_mutex_t	*fork;
}				t_philosopher;


typedef struct	s_all
{
		t_philosopher philosophers;
}			t_all;
