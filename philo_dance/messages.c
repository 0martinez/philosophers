/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:58:16 by omartine          #+#    #+#             */
/*   Updated: 2022/05/13 19:01:43 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	compare_times(t_philo *philo)
{
	return (((philo->timer2.tv_sec - philo->timer1.tv_sec) * 1000) + ((philo->timer2.tv_usec - philo->timer1.tv_usec) / 1000));
}

void	print_philo_state(t_philo *philo, int state)
{
	double	time;

	if (state == EATING)
	{
		gettimeofday(&philo.timer2, NULL);
		time = compare_times(philo);
		printf("\033[0;32m%.fms Philosopher --%d-- is eating\033[0m\n", time, philo.id);
	}
	if (state == SLEEPING)
	{
		gettimeofday(&philo.timer2, NULL);
		time = compare_times(philo);
		printf("\033[1;34m%.fms Philosopher --%d-- is sleeping, dont disturb pls...\033[0m\n", time, philo.id);
	}
	if (state == THINKING)
	{
		gettimeofday(&philo.timer2, NULL);
		time = compare_times(philo);
		printf("\033[1;33m%.fms Philosopher --%d-- is thinking...\033[0m\n", time, philo.id);
	}
	if (state == RIGHT_FORK)
	{
		gettimeofday(&philo.timer2, NULL);
		time = compare_times(philo);
		printf("%.fms Philosopher --%d-- grabbed a fork(right)\n", time, philo.id);

	}
	//	printf("Philosopher %d just grabbed the fork of his right\n", philo.id);
	if (state == LEFT_FORK)
	{
		gettimeofday(&philo.timer2, NULL);
		time = compare_times(philo);
		printf("%.fms Philosopher --%d-- grabbed a fork(left)\n", time, philo.id);
	}
	//	printf("Philosopher %d just grabbed the fork of his left\n", philo.id);
	if (state == RIGHT_FORK_LEFT)
	{
		gettimeofday(&philo.timer2, NULL);
		time = compare_times(philo);
		printf("%.fms Philosopher --%d-- LEFT a fork(right)\n", time, philo.id);
	}
	if (state == LEFT_FORK_LEFT)
	{
		gettimeofday(&philo.timer2, NULL);
		time = compare_times(philo);
		printf("%.fms Philosopher --%d-- LEFT a fork(left)\n", time, philo.id);
	}
}
