/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 18:56:53 by omartine          #+#    #+#             */
/*   Updated: 2022/05/20 20:37:09 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

double	compare_times(t_philo *philo)
{
	return (((philo->timer2.tv_sec - philo->timer1.tv_sec) * 1000) + ((philo->timer2.tv_usec - philo->timer1.tv_usec) / 1000));
}

void	print_philo_state(t_philo *philo, int state)
{
	double	time;

	if (state == EATING)
	{
		gettimeofday(&philo->timer2, NULL);
		time = compare_times(philo);
		printf("🍝 \033[1m\033[32m%.fms Philosopher --%d-- is eating\033[0m 🍝	\n", time, philo->id + 1);
	}
	if (state == SLEEPING)
	{
		gettimeofday(&philo->timer2, NULL);
		time = compare_times(philo);
		printf("💤 \033[1;34m%.fms Philosopher --%d-- is sleeping, dont disturb pls\033[0m 💤\n", time, philo->id + 1);
	}
	if (state == THINKING)
	{
		gettimeofday(&philo->timer2, NULL);
		time = compare_times(philo);
		printf("💭 \033[1;33m%.fms Philosopher --%d-- is thinking\033[0m 💭\n", time, philo->id + 1);
	}
	if (state == RIGHT_FORK)
	{
		gettimeofday(&philo->timer2, NULL);
		time = compare_times(philo);
		printf("🍴 \033[1m\033[35m%.fms Philosopher --%d-- grabbed a fork(right)\033[0m 🍴\n", time, philo->id + 1);

	}
	if (state == LEFT_FORK)
	{
		gettimeofday(&philo->timer2, NULL);
		time = compare_times(philo);
		printf("🍴 \033[1m\033[35m%.fms Philosopher --%d-- grabbed a fork(left)\033[0m 🍴\n", time, philo->id + 1);
	}
	if (state == RIGHT_FORK_LEFT)
	{
		gettimeofday(&philo->timer2, NULL);
		time = compare_times(philo);
		printf("🍴 \033[1m\033[35m%.fms Philosopher --%d-- LEFT a fork(right)\033[0m 🍴\n", time, philo->id + 1);
	}
	if (state == LEFT_FORK_LEFT)
	{
		gettimeofday(&philo->timer2, NULL);
		time = compare_times(philo);
		printf("🍴 \033[1m\033[35m%.fms Philosopher --%d-- LEFT a fork(left)\033[0m 🍴\n", time, philo->id + 1);
	}
}
