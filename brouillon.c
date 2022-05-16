#include "philo.h"

int init_mutex(t_data *rules)
{
	int i;

	i = 1;
	(void) *rules;
	if (i == 0)
		return (1);
	return (0);
}

int usr(t_data *rules)
{
	if (init_mutex(rules))
		return (2);
	return (0);
}

int main(void)
{
	t_data *rules;
	printf("%d\n", usr(rules));
	return (0);
}