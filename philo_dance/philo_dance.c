/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_dance.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 19:04:09 by omartine          #+#    #+#             */
/*   Updated: 2022/04/26 16:01:59 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*b2b_philo(void *p)
{
	t_philo			*philo;
	int				philo_state;
	struct timeval	timer;
	struct timeval	move_end;

	philo = (t_philo *) p;
	pthread_mutex_lock(&philo->righ_fork);
	pthread_mutex_lock(&philo->left_fork);
	philo_eat(*philo);
	pthread_mutex_unlock(&philo->left_fork);
	pthread_mutex_unlock(&philo->righ_fork);
	philo_state = philo_sleep(*philo, &timer);
	if (philo_state == DEAD)
	{
		pthread_join(philo[0].philo_thread, NULL);
		return (0);
	}
	

}

void	philo_dance(t_philo *philo)
{
	int	i;

	i = 0;
	//and here, just right here, is where the dance just start
	pthread_create(&philo[i].philo_thread, NULL, b2b_philo, (void *)&philo[i]);
	pthread_join(philo[i].philo_thread, NULL);
}
