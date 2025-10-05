/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginobile <ginobile@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 16:53:55 by ginobile          #+#    #+#             */
/*   Updated: 2025/10/05 16:53:56 by ginobile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	is_valid_input(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] < 48 || s[i] > 57)
			return (false);
		i++;
	}
	return (true);
}

int	simple_atoi(char *s)
{
	int	res;
	int	i;

	i = 0;
	res = 0;
	while (s[i])
	{
		res = res * 10;
		res = res + (s[i] - '0');
		i++;
	}
	return (res);
}
