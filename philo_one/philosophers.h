/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbabeau <gbabeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 14:43:39 by gbabeau           #+#    #+#             */
/*   Updated: 2021/07/19 17:24:49 by gbabeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>
# include <unistd.h>

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
	int 			finish;
	long long		time;
	long long		start;
	pthread_mutex_t	*fork;
	pthread_mutex_t	*general;
	pthread_mutex_t	*display;
}	t_chrono;

typedef struct s_philosopher
{
	long long		last_eat;
	int				num;
	int				each;
	int				etat;
	char			*etat_str;
	pthread_t		thread_id;
	pthread_t		display_id;
	int				fork[2];
	pthread_mutex_t	*general;
	pthread_mutex_t	*display;
	t_chrono		*chrono;
}	t_philosopher;

void				*test( void *arg);
void				*test_to_live( void *arg);
void				init_philosophers(int number_of_philosopher,
						t_chrono *all, t_philosopher *philosophers);
long long			ft_time(void);
int					display(t_philosopher *philosophers, char *etat);
void				ft_putnbr_fd(int nb, int fd);
long long			ft_time(void);
void				ft_usleep(long long time, long long time_2);
int					ft_atoi(const char *str);
int					ft_compare_c_to_s(char c, char *str);
int					check_init(char *str);
#endif
