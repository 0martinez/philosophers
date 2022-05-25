/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 18:05:53 by omartine          #+#    #+#             */
/*   Updated: 2022/05/25 19:20:37 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_atoi(char *str)
{
	int	num;

	if (!str)
		exit(0);
	if (str[0] == 0)
	{
		write(1, "empty str", 9);
		exit(0);
	}
	num = ft_atoi(str);
	if (num < 0)
	{
		write(1, "negative numbers are not allowed", 32);
		exit(0);
	}
	return (num);
}

t_terms	*init_terms(int argc, char **argv)
{
	t_terms	*philo;

	if (argc != 5 && argc != 6)
	{
		write(1, "Incorrect num of arguments", 26);
		exit (0);
	}
	philo = malloc(sizeof(t_terms));
	if (!philo)
		exit(0);
	philo->num_of_philo = check_atoi(argv[1]);
	philo->time_to_die = check_atoi(argv[2]);
	philo->time_to_eat = check_atoi(argv[3]);
	philo->time_to_sleep = check_atoi(argv[4]);
	if (argc == 6)
		philo->num_of_eats = check_atoi(argv[5]);
	else
		philo->num_of_eats = DISABLED;
	if (philo->num_of_philo < 2 || philo->time_to_die <= 0
		|| philo->time_to_eat <= 0 || philo->time_to_sleep <= 0)
		exit (0);
	return (philo);
}

void	init_mutex(t_philo *philo)
{
	philo->state = ALIVE;
	philo->fork = malloc (sizeof(pthread_mutex_t));
	pthread_mutex_init(philo->fork, NULL);
}

t_philo	*init_philo(t_terms *philo_terms)
{
	t_philo	*philo;
	t_philo	*aux;
	int		i;

	i = 0;
	philo = malloc(sizeof(t_philo));
	if (!philo)
		exit(0);
	while (i < philo_terms->num_of_philo)
	{
		philo->r_philo = malloc(sizeof(t_philo));
		init_mutex(philo);
		philo->philo_terms = *philo_terms;
		if (!philo->r_philo || !philo->fork)
			exit(0);
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
