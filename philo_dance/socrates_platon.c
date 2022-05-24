/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   socrates_platon.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 18:36:28 by omartine          #+#    #+#             */
/*   Updated: 2022/05/24 18:00:24 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*socrates(void *arg)
{
	t_philo	*philo;
	int		n_eats;

	philo = (t_philo *)arg;
	n_eats = 0;
	gettimeofday(&philo->start_time, NULL);
	while (n_eats != philo->philo_terms.num_of_eats)
	{
		pthread_mutex_lock(philo->fork);
		print_philo_state(philo, LEFT_FORK);
		pthread_mutex_lock(philo->r_philo->fork);
		philo->state = EATING;
		n_eats++;
		print_philo_state(philo, RIGHT_FORK);
		print_philo_state(philo, EATING);
		philo->state = philo_eat(philo);
		pthread_mutex_unlock(philo->fork);
		print_philo_state(philo, LEFT_FORK_LEFT);
		pthread_mutex_unlock(philo->r_philo->fork);
		print_philo_state(philo, RIGHT_FORK_LEFT);
		print_philo_state(philo, SLEEPING);
		philo->state = philo_sleep(philo);
		if (philo->state == DEAD)
		{
			printf("philo %d died", philo->id + 1);
			exit(0);
		}
		print_philo_state(philo, THINKING);
	}
	return (0);
}

void	*platon(void *arg)
{
	t_philo	*philo;
	int		n_eats;

	philo = (t_philo *)arg;
	n_eats = 0;
	gettimeofday(&philo->start_time, NULL);
	while (n_eats != philo->philo_terms.num_of_eats)
	{
		pthread_mutex_lock(philo->r_philo->fork);
		print_philo_state(philo, RIGHT_FORK);
		pthread_mutex_lock(philo->fork);
		philo->state = EATING;
		n_eats++;
		print_philo_state(philo, LEFT_FORK);
		print_philo_state(philo, EATING);
		philo->state = philo_eat(philo);
		pthread_mutex_unlock(philo->r_philo->fork);
		print_philo_state(philo, RIGHT_FORK_LEFT);
		pthread_mutex_unlock(philo->fork);
		print_philo_state(philo, LEFT_FORK_LEFT);
		print_philo_state(philo, SLEEPING);
		philo->state = philo_sleep(philo);
		if (philo->state == DEAD)
		{
			printf("philo %d died", philo->id + 1);
			exit(0);
		}
		print_philo_state(philo, THINKING);
	}
	return (0);
}
