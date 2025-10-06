/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginobile <ginobile@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 16:53:59 by ginobile          #+#    #+#             */
/*   Updated: 2025/10/06 10:31:51 by ginobile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	are_all_numbers(int argc, char **argv)
{
	int	i;

	i = 1;
	(void)argc;
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
	if (gmu->forks)
		destroy_forks(gmu);
	free(gmu->forks);
	free(gmu->philos);
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
	gmu.philos_number = simple_atoi(argv[1]);
	gmu.time_to_die = simple_atoi(argv[2]);
	gmu.time_to_eat = simple_atoi(argv[3]);
	gmu.time_to_sleep = simple_atoi(argv[4]);
	if (gmu.philos_number == 0 || gmu.time_to_die == 0
		|| gmu.time_to_eat == 0 || gmu.time_to_sleep == 0)
		error_exit(&gmu);
	if (argc == 6)
	{
		gmu.meals_to_finish_present = true;
		gmu.meals_to_finish = (size_t) simple_atoi(argv[5]);
	}
	if (argc == 6 && gmu.meals_to_finish == 0)
		error_exit(&gmu);
	simulation(&gmu);
}
