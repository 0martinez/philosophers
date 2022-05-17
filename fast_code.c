/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fast_code.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:35:05 by omartine          #+#    #+#             */
/*   Updated: 2022/05/17 19:30:56 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t	mutex1;
pthread_mutex_t	mutex2;

t_terms	*init_terms(char **argv, int argc)
{
	t_terms	*philo;

	if (argc != 6 && argc != 7)
	{
		write(1, "Incorrect num of arguments", 26);
		exit (0);
	}
	philo = malloc(sizeof(t_terms));
	if (!philo)
		exit(0);
	philo->num_of_philo = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 7)
		philo->num_of_eats = ft_atoi(argv[5]);
	else
		philo->num_of_eats = DISABLED;
	if (philo->num_of_philo < 2 || philo->time_to_die <= 0 || philo->time_to_eat <= 0
		|| philo->time_to_sleep <= 0)
		exit (0);
	return (philo);
}

t_philo	*philo_init(t_terms *philo_terms)
{
	t_philo	*philo;
	t_philo	*aux;
	int		i;

	i = 0;
	philo = malloc(sizeof(t_philo));
	aux = malloc(sizeof(t_philo));
	if (!aux || !philo)
	{
		write(1, "Error during malloc", 19);
		exit(0);
	}
	while (i < philo_terms->num_of_philo)
	{
		philo->r_philo = malloc(sizeof(t_philo));
		if (!philo->r_philo)
		{
			write(1, "Error during malloc", 19);
			exit(0);
		}
		philo->id = i;
		if (i == 0)
			aux = philo;
		if (i == philo_terms->num_of_philo - 1)
			philo->r_philo = aux;
		philo = philo->r_philo;
		i++;
	}
	return (philo);
}

void	*ft_phi(void	*xd)
{
	t_philo	*philo;

	philo = (t_philo *)xd;
	/*while (1)
	{
		pthread_mutex_lock(&philo->fork);
		print_philo_state(philo, LEFT_FORK);
		pthread_mutex_lock(&philo->r_philo->fork);
		print_philo_state(philo, RIGHT_FORK);
		print_philo_state(philo, EATING);
		philo_eat(philo);
		pthread_mutex_unlock()
	}*/
	//pthread_mutex_lock(&mutex1);
	//pthread_mutex_lock(&mutex2);
	pthread_mutex_lock(philo->fork);
	pthread_mutex_lock(philo->r_philo->fork);
	write(1, "a", 1);
	write(1, "im philo ", 8);
	write(1, ft_itoa(philo->id), 1);
	while (1)
	{
		sleep(1);
	}
	return (0);
}

void	dance_philo(t_philo *philo, t_terms *philo_terms)
{
	int				i;
	//struct timeval	xd;

	i = 0;
	//gettimeofday(&xd, 0);
	//pthread_mutex_init(&mutex1, NULL);
	//pthread_mutex_init(&mutex2, NULL);
	while (i < philo_terms->num_of_philo)
	{
		philo->fork = malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(philo->fork, NULL);
		pthread_create(&philo->philo_thread, NULL, ft_phi, (void *)&philo);
		usleep(500000);
		philo = philo->r_philo;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_terms	*philo_terms;
	t_philo	*philos;

	philo_terms = init_terms(argv, argc);
	philos = philo_init(philo_terms);
	dance_philo(philos, philo_terms);
	while(1)
	{
		sleep(1);
	}
	return (0);
}
