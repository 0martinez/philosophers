/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 12:52:51 by omartine          #+#    #+#             */
/*   Updated: 2022/04/21 12:58:32 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
}*/

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

	printf("Before Thread\n");
	pthread_create(&thread_id, NULL, print_msg, NULL);
	pthread_join(thread_id, NULL);
	printf("After Thread\n");
	exit(0);
}
