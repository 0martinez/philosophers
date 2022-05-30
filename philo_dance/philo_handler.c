/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 18:28:18 by omartine          #+#    #+#             */
/*   Updated: 2022/05/30 19:42:17 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

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
