/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 18:28:18 by omartine          #+#    #+#             */
/*   Updated: 2022/05/28 19:19:16 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	philo_dead(t_philo *philo)
{
	gettimeofday(&philo->timer2, NULL);
	printf(RED"☠  %ldms Philosopher --%d-- died\033[0m ☠	",
		((philo->timer2.tv_sec - philo->timer1.tv_sec) * 1000)
		+ ((philo->timer2.tv_usec - philo->timer1.tv_usec) / 1000),
		philo->id + 1);
	exit(0);
}

void	join_philo_thread(t_philo *philo, t_terms *philo_terms)
{
	int	i;

	i = 0;
	while (i < philo_terms->num_of_philo)
	{
		pthread_join(philo->philo_thread, NULL);
		philo = philo->r_philo;
		i++;
	}
}

int	check_time(t_philo *philo, t_terms *philo_terms)
{
	gettimeofday(&philo->check, NULL);
	if (philo->state != EATING
		&& ((philo->check.tv_sec - philo->start_time.tv_sec) * 1000)
		+ ((philo->check.tv_usec - philo->start_time.tv_usec) / 1000)
		>= philo_terms->time_to_die)
	{
		return (1);
	}
	return (0);
}

void	check_philo_state(t_philo *philo, t_terms *philo_terms)
{
	while (philo)
	{
		if (philo->state != EATING && check_time(philo, philo_terms) == 1)
			philo_dead(philo);
		philo = philo->r_philo;
	}
}

void	philo_handler(t_philo *philo, t_terms *philo_terms)
{
	int				i;
	struct timeval	timer;

	i = 0;
	gettimeofday(&timer, NULL);
	while (i < philo_terms->num_of_philo)
	{
		philo->timer1 = timer;
		gettimeofday(&philo->start_time, NULL);
		if (philo->id % 2 == 0)
			pthread_create(&philo->philo_thread, NULL, platon, (void *)philo);
		else
			pthread_create(&philo->philo_thread, NULL, socrates, (void *)philo);
		philo = philo->r_philo;
		i++;
	}
	check_philo_state(philo, philo_terms);
}
