/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 20:09:23 by omartine          #+#    #+#             */
/*   Updated: 2022/04/26 13:51:21 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	evaluate(struct timeval start, struct timeval finish, double time_to_die)
{
	if (((finish.tv_sec - start.tv_sec) * 1000)
		+ ((finish.tv_usec - start.tv_usec) / 1000) >= time_to_die)
		return (1);
	return (0);
}

int	philo_sleep(t_philo philo)
{
	struct timeval	start_sleep;
	struct timeval	wakeup;

	gettimeofday(&start_sleep, NULL);
	gettimeofday(&wakeup, NULL);
	while (((wakeup.tv_sec - start_sleep.tv_sec) * 1000)
		+ ((wakeup.tv_usec - start_sleep.tv_usec) / 1000)
		< philo.philo_terms.time_to_sleep)
	{
		gettimeofday(&wakeup, NULL);
		if (evaluate(start_sleep, wakeup, philo.philo_terms.time_to_die) == 1)
			return (DEAD);
	}
	return (THINKING);
}

void	philo_eat(t_philo philo)
{
	struct timeval	start_eating;
	struct timeval	finish_eating;

	gettimeofday(&start_eating, NULL);
	gettimeofday(&finish_eating, NULL);
	while (((finish_eating.tv_sec - start_eating.tv_sec) * 1000)
		+ ((finish_eating.tv_usec - start_eating.tv_usec) / 1000)
		< philo.philo_terms.time_to_eat)
	{
		gettimeofday(&finish_eating, NULL);
	}
}
