/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginobile <ginobile@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 16:54:14 by ginobile          #+#    #+#             */
/*   Updated: 2025/10/06 12:04:43 by ginobile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_forks(t_table *table)
{
	int	i;

	i = 0;
	table->forks = (t_mutex *)malloc(sizeof(t_mutex) * table->philos_number);
	if (!table->forks)
		error_exit(table);
	while (i < table->philos_number)
	{
		pthread_mutex_init(&table->forks[i], NULL);
		i++;
	}
}

void	init_philos(t_table *table)
{
	int	i;

	i = 0;
	table->philos = (t_philo *)malloc(sizeof(t_philo) * table->philos_number);
	if (!table->philos)
		error_exit(table);
	while (i < table->philos_number)
	{
		table->philos[i] = (t_philo){0};
		table->philos[i].number = i + 1;
		pthread_mutex_init(&table->philos[i].meal_lock, NULL);
		if (i == table->philos_number - 1)
		{
			table->philos[i].right_fork = &table->forks[i];
			table->philos[i].left_fork = &table->forks[0];
		}
		else
		{
			table->philos[i].left_fork = &table->forks[i];
			table->philos[i].right_fork = &table->forks[i + 1];
		}
		table->philos[i].table = table;
		i++;
	}
}

void	start_dinner(t_table *table)
{
	int	i;

	i = 0;
	table->start_time = current_time();
	pthread_mutex_init(&table->print_lock, NULL);
	pthread_mutex_init(&table->sim_lock, NULL);
	while (i < table->philos_number)
	{
		pthread_create(&table->philos[i].id, NULL,
			(void (*))philo_routine, &table->philos[i]);
		i++;
	}
	monitor(table);
}

void	end_dinner(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philos_number)
	{
		pthread_join(table->philos[i].id, NULL);
		pthread_mutex_destroy(&table->philos[i].meal_lock);
		i++;
	}
	destroy_forks(table);
	free(table->forks);
	free(table->philos);
	pthread_mutex_destroy(&table->print_lock);
	pthread_mutex_destroy(&table->sim_lock);
}

void	simulation(t_table *table)
{
	init_forks(table);
	init_philos(table);
	start_dinner(table);
	end_dinner(table);
}
