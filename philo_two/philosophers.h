/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbabeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 15:06:10 by gbabeau           #+#    #+#             */
/*   Updated: 2021/06/02 15:10:05 by gbabeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <semaphore.h>

# define STR_TAKEN "has taken a fork"
# define STR_DIED "died"
# define STR_EAT "is eating"
# define STR_SLEEP "is sleeping"
# define STR_THINK "is thinking"

typedef struct s_chrono
{
	int				number_of_philosopher;
	long long		time_to_die;
	long long		time_to_eat;
	int				time_to_sleep;
	int				number_of_each;
	int				status;
	int				etat;
	long long		time;
	sem_t			*fork;
	sem_t			*general;
	sem_t			*display;
}				t_chrono;

typedef struct s_philosopher
{
	long long		time_to_live;
	long long		last_eat;
	int				num;
	int				each;
	int				etat;
	char			*etat_str;
	pthread_t		thread_id;
	sem_t			*fork;
	sem_t			*general;
	sem_t			*display;
	t_chrono		*chrono;
}				t_philosopher;

void				*test( void *arg);
void				*test_to_live( void *arg);
void				init_philosophers(int number_of_philosopher,
						t_chrono *all, t_philosopher *philosophers);
long long			ft_time(void);
void				*display(t_philosopher *philosophers, char *etat);
void				ft_putnbr_fd(int nb, int fd);
long long			ft_time(void);
void				ft_usleep(long long time, long long time_2);

#endif
