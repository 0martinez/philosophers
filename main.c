/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 19:22:11 by omartine          #+#    #+#             */
/*   Updated: 2022/04/27 19:05:53 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

t_philo	*init_philo(t_terms *philo_terms)
{
	int		i;
	t_philo	*philos;

	i = 0;
	philos = malloc(sizeof(t_philo) * philo_terms->num_of_philo);
	if (!philos)
	{
		write(1, "Error during malloc", 19);
		exit (0);
	}
	while (i < philo_terms->num_of_philo)
	{
		philos[i].philo_terms = *philo_terms;
		philos[i].id = i;
		philos[i].r_fork_position = i;
		pthread_mutex_init(&philos[i].right_fork, NULL);
		if (i == 0)
		{
			philos[i].left_fork = philos[philo_terms->num_of_philo - 1].right_fork;
			philos[i].l_fork_position = philo_terms->num_of_philo - 1;
		}
		else
		{
			philos[i].left_fork = philos[i - 1].right_fork;
			philos[i].l_fork_position = i - 1;
		}
		i++;
	}
	return (philos);
}

int	main(int argc, char **argv)
{
	t_terms	*philo_terms;
	t_philo	*philos;

	philo_terms = init_terms(argv, argc);
	philos = init_philo(philo_terms);
	philo_dance(philos);
	return (0);
}

//just discovered that if we do a exit(), the OS handle the memmoory
//allocated and free it for us. LOVE U MAC
