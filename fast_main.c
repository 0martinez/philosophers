/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fast_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 19:22:11 by omartine          #+#    #+#             */
/*   Updated: 2022/04/22 19:36:44 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_ph	*init_struct(char **argv, int argc)
{
	t_ph	*philo;

	if (argc != 6 && argc != 7)
	{
		write(1, "Incorrect num of arguments", 26);
		exit (0);
	}
	philo = malloc(sizeof(t_ph));
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

void	philo_eat(t_ph *philo_terms, t_philo *)
{
	struct timeval	start_time;

	gettimeofday(&)
}

void	philo_process(t_ph *philo_terms)
{

}

void	init_dance(t_ph *philo_terms)
{

}

int main(int argc, char **argv)
{
	t_philo	*philo_terms;

	philo_terms = init_struct(argv, argc);

}
