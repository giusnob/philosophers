#include "philo.h"

/*
argc = 1
./philo

argc = 5
./philo 4 800 200 200

argc = 6
./philo 4 800 200 200 7

argc = 7
./philo 4 800 200 200 7 1000
*/
bool	are_all_numbers(int argc, char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!is_valid_input(argv[i]))
			return (false);
		i++;
	}
	return (true);
}

void	error_exit(t_table *gmu)
{
	write(2, "Error\n", 6);
	exit(1);
}


int	main(int argc, char **argv)
{
	t_table	gmu;

	gmu = (t_table){0};
	if (argc != 5 && argc != 6)
		error_exit(&gmu);
	if (!are_all_numbers(argc, argv))
		error_exit(&gmu);
	gmu.n_philos = simple_atoi(argv[1]);
	gmu.time_to_die = simple_atoi(argv[2]);
	gmu.time_to_eat = simple_atoi(argv[3]);
	gmu.time_to_sleep = simple_atoi(argv[4]);
	if (gmu.n_philos == 0 || gmu.time_to_die == 0
		|| gmu.time_to_eat == 0 || gmu.time_to_sleep == 0)
		error_exit(&gmu);
	if (argc == 6)
	{
		gmu.meals_to_finish_present = true;
		gmu.meals_to_finish = simple_atoi(argv[5]);
	}
	if (argc == 6 && gmu.meals_to_finish == 0)
		error_exit(&gmu);



}