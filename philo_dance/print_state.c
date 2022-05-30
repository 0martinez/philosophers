/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 18:56:53 by omartine          #+#    #+#             */
/*   Updated: 2022/05/23 14:08:58 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

double	compare_times(t_philo *philo)
{
	return (((philo->timer2.tv_sec - philo->timer1.tv_sec) * 1000)
		+ ((philo->timer2.tv_usec - philo->timer1.tv_usec) / 1000));
}

void	print_actions(t_philo *philo, int state)
{
	double	time;

	gettimeofday(&philo->timer2, NULL);
	time = compare_times(philo);
	if (state == EATING)
	{
		printf(GREEN"🍝 %.fms Philosopher --%d-- is eating 🍝	\n"RESET,
			time, philo->id + 1);
	}
	if (state == SLEEPING)
	{
		printf(BLUE"💤 %.fms Philosopher --%d-- is sleeping 💤\n"RESET,
			time, philo->id + 1);
	}
	if (state == THINKING)
	{
		printf(YELLOW"💭 %.fms Philosopher --%d-- is thinking 💭\n"RESET,
			time, philo->id + 1);
	}
}

void	print_fork(t_philo *philo, int state)
{
	double	time;

	gettimeofday(&philo->timer2, NULL);
	time = compare_times(philo);
	if (state == RIGHT_FORK)
	{
		printf(PURPLE"🍴 %.fms Philosopher --%d-- grabbed a fork(right) 🍴\n"RESET,
			time, philo->id + 1);
	}
	if (state == LEFT_FORK)
	{
		printf(PURPLE"🍴 %.fms Philosopher --%d-- grabbed a fork(left) 🍴\n"RESET,
			time, philo->id + 1);
	}
	if (state == RIGHT_FORK_LEFT)
	{
		printf(PURPLE"🍴 %.fms Philosopher --%d-- LEFT a fork(right) 🍴\n"RESET,
			time, philo->id + 1);
	}
	if (state == LEFT_FORK_LEFT)
	{
		printf(PURPLE"🍴 %.fms Philosopher --%d-- LEFT a fork(left) 🍴\n"RESET,
			time, philo->id + 1);
	}
}

void	print_philo_state(t_philo *philo, int state)
{
	if (state == EATING || state == SLEEPING || state == THINKING)
		print_actions(philo, state);
	else
		print_fork(philo, state);
}
