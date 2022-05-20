/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   socrates.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 18:36:28 by omartine          #+#    #+#             */
/*   Updated: 2022/05/20 19:30:19 by omartine         ###   ########.fr       */
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
	//while (philo->state != DEAD || philo->philo_terms->num_of_eats != n_eats)
	while (1)
	{
		pthread_mutex_lock(philo->fork);
		print_philo_state(philo, LEFT_FORK);
		pthread_mutex_lock(philo->r_philo->fork);
		philo->state = EATING;
		print_philo_state(philo, RIGHT_FORK);
		print_philo_state(philo, EATING);
		philo->state = philo_eat(philo);
		pthread_mutex_unlock(philo->fork);
		print_philo_state(philo, LEFT_FORK_LEFT);
		pthread_mutex_unlock(philo->r_philo->fork);
		print_philo_state(philo, RIGHT_FORK_LEFT);
		print_philo_state(philo, SLEEPING);
		philo->state = philo_sleep(philo);
		print_philo_state(philo, THINKING);
	}
}
