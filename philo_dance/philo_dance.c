/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_dance.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 19:04:09 by omartine          #+#    #+#             */
/*   Updated: 2022/04/27 13:53:31 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	print_philo_state(t_philo philo, int state)
{
	if (state == EATING)
		printf("Philosopher %d is eating", philo.id);
	if (state == SLEEPING)
		printf("Philosopher %d is sleeping, dont disturb him pls", philo.id);
	if (state == THINKING)
		printf("Philosopher %d is thinking...", philo.id);
	if (state == RIGHT_FORK)
		printf("Philosopher %d just grabbed the fork of his right", philo.id);
	if (state == LEFT_FORK)
		printf("Philosopher %d just grabbed the fork of his left", philo.id);
}

void	*b2b_philo(void *p)
{
	t_philo			*philo;
	int				philo_state;
	struct timeval	timer;
	struct timeval	move_end;
	int				eats_counter;

	philo = (t_philo *) p;
	eats_counter = 0;
	printf("id --- %d", philo[0].id);
	pthread_mutex_lock(&philo->righ_fork);
	print_philo_state(philo[0], RIGHT_FORK);
	pthread_mutex_lock(&philo->left_fork);
	print_philo_state(philo[0], LEFT_FORK);
	print_philo_state(philo[0], EATING);
	philo_eat(*philo);
	pthread_mutex_unlock(&philo->left_fork);
	pthread_mutex_unlock(&philo->righ_fork);
	print_philo_state(philo[0], SLEEPING);
	philo_state = philo_sleep(*philo, &timer);
	if (philo_state == DEAD)
	{
		pthread_join(philo[0].philo_thread, NULL);
		return (0);
	}
	pthread_join(philo[0].philo_thread, NULL);
	return (0);
}

void	philo_dance(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->philo_terms.num_of_philo)
	{
		write(1, "hola", 4);
		pthread_create(&philo[i].philo_thread, NULL, b2b_philo, (void *)&philo[i]);
		i++;
	}
}
