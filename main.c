

#include "philo.h"

void	print_msg(void *arg)
{

}



t_ph	*init_struct(char **argv)
{
	t_ph	*philo;

	philo = malloc(sizeof(t_ph));
	if (!philo)
		exit(0);
	philo->num_of_philo = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	philo->num_of_eats = ft_atoi(argv[5]);
	return (philo);
}


int	main(int argc, char **argv)
{
	
	
	pid_t	pd;
	pthread_t	h1;
	pthread_t	h2;
	t_ph		*philo;

	if (argc != 5)
	{
		write(1, "Incorrect num of arguments", 26);
		return (0);
	}
	philo = init_struct(argv);
	pd = fork();
	pthread_create(&h1, NULL, print_msg, NULL);
	while (1)
		i++;
}