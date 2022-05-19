/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 18:28:18 by omartine          #+#    #+#             */
/*   Updated: 2022/05/19 19:56:31 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	philo_handler(t_philo *philo, t_terms *philo_terms)
{
	int	i;

	i = 0;
	while (i < philo_terms->num_of_philo)
	{
		gettimeofday(&philo->timer1, NULL);
		pthread_create(&philo->philo_thread, NULL, socrates, (void *)philo);
		usleep(500000);
		philo = philo->r_philo;
		i++;
	}
	while (1)
	{
		sleep(1);
	}
}
