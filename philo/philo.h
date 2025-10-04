#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>

typedef enum e_action
{
	ACTION_SLEEP,
	ACTION_THINK,
	ACTION_EAT,
	ACTION_TAKE_FORK,
	ACTION_DEATH
}	t_action;

typedef pthread_mutex_t	t_mutex;

typedef struct s_philo
{
	t_mutex			*left_fork;
	t_mutex			*right_fork;
	int				number;
	pthread_t		id;
	size_t			n_meals;
	size_t			last_meal_time;
	t_mutex			meal_lock;

	struct s_table	*gmu;
}	t_philo;

typedef struct s_table
{
	t_mutex	*forks;
	t_philo	*philos;
	int		n_philos;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;

	bool	meals_to_finish_present;
	size_t	meals_to_finish;

	t_mutex	print_lock;

	t_mutex	sim_lock;
	bool	sim_finished;

	size_t	start_time;
}	t_table;

bool	are_all_numbers(int argc, char **argv);
size_t	current_time();
void	destroy_forks(t_table *gmu);
void	eat(t_philo *philo);
void	end_dinner(t_table *gmu);
void	error_exit(t_table *gmu);
size_t	get_n_meals(t_philo *philo);
void	init_forks(t_table *gmu);
void	init_philos(t_table *gmu);
bool	is_sim_finished(t_table *gmu);
bool	is_valid_input(char *s);
void	monitor(t_table *gmu);
void	philo_routine(t_philo *philo);
void	print_action(t_philo *philo, t_action act);
void	release_forks(t_philo *philo);
void	set_sim_finished(t_table *gmu, bool s_finish);
int		simple_atoi(char *s);
void	simulation(t_table *gmu);
void	start_dinner(t_table *gmu);
void	take_forks(t_philo *philo);

# endif