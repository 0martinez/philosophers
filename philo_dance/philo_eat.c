/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 20:09:23 by omartine          #+#    #+#             */
/*   Updated: 2022/04/23 20:23:17 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	philo_eat(struct timeval time_to_die, t_philo philo)
{
	struct timeval	start_eating;
	struct timeval	finish_eating;

	gettimeofday(&start_eating, NULL);
	gettimeofday(&finish_eating, NULL);
	while (((finish_eating.tv_sec - start_eating.tv_sec) * 1000) + ((finish_eating.tv_usec - start_eating.tv_usec) / 1000) < philo_terms->time_to_eat)
}

void	philo_eat(t_terms *philo_terms, t_philo *philo)
{
	struct timeval	start_time;
	struct timeval	finish_time;

	philo->state_of_philo = EATING;
	//probably i must lock both forks here, but i dont know how thw fuck do it xddd
	gettimeofday(&start_time, NULL);
	gettimeofday(&finish_time, NULL);
	while (((finish_time.tv_sec - start_time.tv_sec) * 1000) + ((finish_time.tv_usec - start_time.tv_usec) / 1000) < philo_terms->time_to_eat)
		gettimeofday(&finish_time, NULL);
}
