#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>

typedef struct s_table
{
	int		n_philos;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;

	bool	meals_to_finish_present;
	int		meals_to_finish;
}	t_table;

bool	are_all_numbers(int argc, char **argv);
bool	is_valid_input(char *s);
void	simulation(t_table *gmu);
int		simple_atoi(char *s);

# endif