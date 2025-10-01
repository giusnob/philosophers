#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>

typedef pthread_mutex_t	t_mutex;

typedef struct s_philo
{
	t_mutex	*left_fork;
	t_mutex	*right_fork;

	struct s_table	*gmu;
}	t_philo;

typedef struct s_table
{
	t_mutex	*forks;
	t_philo *philos;
	int		n_philos;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;

	bool	meals_to_finish_present;
	int		meals_to_finish;
}	t_table;


bool	are_all_numbers(int argc, char **argv);
void	destroy_forks(t_table *gmu);
void	error_exit(t_table *gmu);
bool	is_valid_input(char *s);
void	simulation(t_table *gmu);
int		simple_atoi(char *s);

# endif