/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 12:52:51 by omartine          #+#    #+#             */
/*   Updated: 2022/04/22 19:21:46 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "philo.h"

/*
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
	if (philo->num_of_philo < 2 || philo->time_to_die <= 0 || philo->time_to_eat <= 0
			|| philo->time_to_sleep <= 0)
		exit (0);
	return (philo);
}

#include "philo.h"

void	*print_msg(void *arg)
{
	sleep(1);
	printf("in the thread\n");
	return (0);
}

int	main(void)
{
	//pid_t	pd;
	//pthread_t	h1;
	//pthread_t	h2;
	//t_ph		*philo;

	//if (argc != 6)
	//{
	//	write(1, "Incorrect num of arguments", 26);
	//	return (0);
	//}
	//philo = init_struct(argv);
	pthread_t	thread_id;
	struct timeval start;
	struct timeval end;


	gettimeofday(&start, NULL);
	loopFunc(NUM2);
	gettimeofday(&end, NULL);

	printf("Before Thread\n");
	pthread_create(&thread_id, NULL, print_msg, NULL);
	pthread_join(thread_id, NULL);
	printf("After Thread\n");
	exit(0);
}*/

int main(void)
{
	/*struct timeval	hola;
	struct timeval	adios;
	long			i;

	gettimeofday(&hola, NULL);
	i = 0;
	hola.t
	while ((adios.tv_sec - hola.tv_sec) < 5)
	{
		gettimeofday(&adios, NULL);
		i++;
	}
	//sleep(2);
	//gettimeofday(&adios, NULL);
	printf("HAN PASADO %ld SEGUNDOS----------i = %ld", (adios.tv_sec - hola.tv_sec), i);
	//printf("seconds : %ld\nmicro seconds : %ld", hola.tv_sec, hola.tv_usec);*/

	struct timeval ti, tf;
    double tiempo;
    gettimeofday(&ti, NULL);   // Instante inicial
    printf("Lee este mensaje y pulsa ENTER\n");
    getchar();
    gettimeofday(&tf, NULL);   // Instante final
    tiempo= (tf.tv_sec - ti.tv_sec)*1000 + (tf.tv_usec - ti.tv_usec)/1000.0;
    printf("Has tardado: %g milisegundos\n", tiempo);
	return (0);
}


//testeo comportamiento de un filosofo

void	filo(void)
{
	//empezará comiendo
	struct	timeval time_x;
	struct	timeval time_eating;

	while (both_forks_are_not_unable)
	{
		if (time_waitng > time_to_die)
		{
			//thinking in a var to determinate the state of the philo
			//terminate the thread and wait to the other philo to die
			//but thincking a bit, the fact that a philo(thread) dies
			//doesnt means that all the philos must die because we have more
			//forks unable, gg xd. the problem is that the subject
			//dont want to allow us a dead of a philo xddd
			//ok ,back in the business
			pthread_join(this_philo_dies);
		}
		gettime
	}

	//lets start to eat
	if (both_forks_are_unable)
	{
		//hacer lock de ambos tenedores y cuando termine el bucle desbloquearlos
		//tendra una variable que registrará el milisegundo con la ft gettimeofday
		//en el que ha empezado a comer, y otra que estará constamente registrando
		//el tiempo que lleva realizando esa tarea
		//estas dos variables estarán almacenados en structs timeval

		gettimeofday(&time_x, NULL);
		gettimeofday(&time_eating, NULL);

		while (((time_eating.tv_sec - time_x.tv_sec) * 1000) + ((time_eating.tv_usec - time_x.tv_usec) / 1000) < time_that_philo_must_eat)
		{
			gettimeofday(&time_eating, NULL);
		}
		//unlock de tenedores

	}
	//im thinking that the last loop is going to be very similar so that is
	//not going to be a taught task
	//now its time to learn a bit about mutex and try to figure how to do
	//
}
