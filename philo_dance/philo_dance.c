/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_dance.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 19:04:09 by omartine          #+#    #+#             */
/*   Updated: 2022/04/26 13:54:50 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*b2b_philo(void *p)
{
	t_philo	*philo;
	int		philo_state;

	philo = (t_philo *) p;
	//printf("%d", philo[0].id);
	//printf("%d", philo->philo_terms.num_of_philo);
	pthread_mutex_lock(&philo->righ_fork);
	pthread_mutex_lock(&philo->left_fork);
	philo_eat(*philo);
	//printf("hello world, im just a thread that is going to be dead in just a second");
	//printf("id--%d\nrf_pos--%d\nlf_pos%d\n\n", philo->id, philo->r_fork_position, philo->l_fork_position);
	return (0);
}

void	philo_dance(t_philo *philo)
{
	int	i;

	i = 0;
	//and here, just right here, is where the dance just start
	pthread_create(&philo[i].philo_thread, NULL, b2b_philo, (void *)&philo[i]);
	//while (i < philo_terms->num_of_philo)
	//{
	//	pthread_create(&philo[i].philo_thread, NULL, philo_moves, (void *)philo);
	//}
	pthread_join(philo[i].philo_thread, NULL);
}
