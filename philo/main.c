/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginobile <ginobile@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 16:53:59 by ginobile          #+#    #+#             */
/*   Updated: 2025/10/20 19:09:21 by ginobile         ###   ########.fr       */
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

void	error_exit(t_table *table)
{
	write(2, "Error\n", 6);
	if (table->forks)
		destroy_forks(table);
	free(table->forks);
	free(table->philos);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_table	table;

	table = (t_table){0};
	if (argc != 5 && argc != 6)
		error_exit(&table);
	if (!are_all_numbers(argc, argv))
		error_exit(&table);
	table.philos_number = ft_atoi(argv[1]);
	table.time_to_die = ft_atoi(argv[2]);
	table.time_to_eat = ft_atoi(argv[3]);
	table.time_to_sleep = ft_atoi(argv[4]);
	if (table.philos_number == 0 || table.time_to_die == 0
		|| table.time_to_eat == 0 || table.time_to_sleep == 0)
		error_exit(&table);
	if (argc == 6)
	{
		table.meals_to_finish_present = true;
		table.meals_to_finish = (size_t) ft_atoi(argv[5]);
	}
	if (argc == 6 && table.meals_to_finish == 0)
		error_exit(&table);
	simulation(&table);
}
