/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 19:06:32 by omartine          #+#    #+#             */
/*   Updated: 2022/05/23 14:09:30 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	philo_eat(t_philo *philo)
{
	struct timeval	start_eating;
	struct timeval	finish_eating;

	gettimeofday(&start_eating, NULL);
	gettimeofday(&finish_eating, NULL);
	while (((finish_eating.tv_sec - start_eating.tv_sec) * 1000)
		+ ((finish_eating.tv_usec - start_eating.tv_usec) / 1000)
		<= philo->philo_terms.time_to_eat)
	{
		gettimeofday(&finish_eating, NULL);
	}
	gettimeofday(&philo->start_time, NULL);
	return (SLEEPING);
}

int	philo_sleep(t_philo *philo)
{
	struct timeval	start_sleeping;
	struct timeval	finish_sleeping;

	gettimeofday(&start_sleeping, NULL);
	gettimeofday(&finish_sleeping, NULL);
	while (((finish_sleeping.tv_sec - start_sleeping.tv_sec) * 1000)
		+ ((finish_sleeping.tv_usec - start_sleeping.tv_usec) / 1000)
		<= philo->philo_terms.time_to_sleep)
	{
		gettimeofday(&finish_sleeping, NULL);
	}
	return (SLEEPING);
}
