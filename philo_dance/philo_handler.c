/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 18:28:18 by omartine          #+#    #+#             */
/*   Updated: 2022/05/20 20:30:51 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	check_if_die(t_philo *philo, t_terms *philo_terms)
{
	int	i;

	i = 0;
	gettimeofday(&philo->check, NULL);
	if (philo->state != EATING && ((philo->check.tv_sec - philo->start_time.tv_sec) * 1000)
		+ ((philo->check.tv_usec - philo->start_time.tv_usec) / 1000)
		>= philo_terms->time_to_die)
	{
		return (1);
	}
	return (0);
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
		pthread_create(&philo->philo_thread, NULL, socrates, (void *)philo);
		usleep(100000);
		philo = philo->r_philo;
		i++;
	}
	while (1)
	{
		if (check_if_die(philo, philo_terms) == 1)
		{
			gettimeofday(&philo->timer2, NULL);
			printf("☠  \033[1m\033[31m%ldms Philosopher --%d-- died\033[0m ☠	", ((philo->timer2.tv_sec - philo->timer1.tv_sec) * 1000) + ((philo->timer2.tv_usec - philo->timer1.tv_usec) / 1000), philo->id + 1);
			//printf("\033[1m\033[31m%ld philo %d died\033[0m", philo->id);

			exit(0);
		}
		philo = philo->r_philo;
	}
}
