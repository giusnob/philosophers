#include "philo.h"

bool	is_valid_input(char *s)
{
	int i;

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

	return (res);
}