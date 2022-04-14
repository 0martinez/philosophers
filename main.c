

#include "philo.h"

void	print_msg(void *arg)
{

}

int	main(int argc, char **argv)
{
	
	// if (argc != 5)
	// {
	// 	write(1, "Incorrect num of arguments", 26);
	// 	return (0);
	// }
	pid_t	pd;
	pthread_t	h1;
	pthread_t	h2;
	int		i = 0;
	pd = fork();
	pthread_create(&h1, NULL, print_msg, NULL);
	while (1)
		i++;
}