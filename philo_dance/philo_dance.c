/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_dance.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 19:04:09 by omartine          #+#    #+#             */
/*   Updated: 2022/05/11 16:31:51 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

pthread_mutex_t	mutex1;
pthread_mutex_t	mutex2;

double	compare_times(t_philo philo)
{
	return (((philo.timer2.tv_sec - philo.timer1.tv_sec) * 1000) + ((philo.timer2.tv_usec - philo.timer1.tv_usec) / 1000));
}

void	print_philo_state(t_philo philo, int state)
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

void	*b2b_philo(void *p)
{
	t_philo			*philo;
	//int				philo_state;
	//struct timeval	timer;
	int	i = 0;
	//int				eats_counter;

	philo = (t_philo *) p;
	//gettimeofday(&philo[0].timer1, NULL);
	//eats_counter = 0;
	write(1, "philo ", 6);
	write(1, ft_itoa(philo[0].id), 1);
	write(1, "created\n", 8);
	while (i > -1)
	{
		if (philo[0].id == 1)
		{
			printf("---%d---", philo[1].testing);
			getchar();
		}

		/*pthread_mutex_lock(&philo->right_fork);
		print_philo_state(philo[0], RIGHT_FORK);
		pthread_mutex_lock(&philo->left_fork);
		print_philo_state(philo[0], LEFT_FORK);
		print_philo_state(philo[0], EATING);
		philo_eat(*philo);
		pthread_mutex_unlock(&philo->left_fork);
		print_philo_state(philo[0], LEFT_FORK_LEFT);
		pthread_mutex_unlock(&philo->right_fork);
		print_philo_state(philo[0], RIGHT_FORK_LEFT);
		print_philo_state(philo[0], SLEEPING);
		philo_sleep(*philo, &timer); //return philo_state
		print_philo_state(philo[0], THINKING);*/
		/*
		pthread_mutex_lock(&mutex1);
		print_philo_state(philo[0], LEFT_FORK);
		pthread_mutex_lock(&mutex2);
		print_philo_state(philo[0], RIGHT_FORK);
		print_philo_state(philo[0], EATING);
		philo_eat(*philo);
		pthread_mutex_unlock(&mutex1);
		print_philo_state(philo[0], LEFT_FORK_LEFT);
		pthread_mutex_unlock(&mutex2);
		print_philo_state(philo[0], RIGHT_FORK_LEFT);
		print_philo_state(philo[0], SLEEPING);
		philo_sleep(*philo, &timer); //return philo_state
		print_philo_state(philo[0], THINKING);*/
		/*if (philo_state == DEAD)
		{
			write (1, "F IN CHAT", 9);
			pthread_join(philo[0].philo_thread, NULL);
			return (0);
		}*/
		i++;
	}
	pthread_join(philo[0].philo_thread, NULL);
	write(1, "sale pa", 7);
	return (0);
}

void	philo_dance(t_philo *philo, t_terms *philo_terms)
{
	int				i;
	struct timeval	xd;

	i = 0;
	pthread_mutex_init(&mutex1, NULL);
	pthread_mutex_init(&mutex2, NULL);
	gettimeofday(&xd, 0);
	philo[0].testing = 777;
	while (i < philo_terms->num_of_philo)
	{
		philo[i].timer1 = xd;
		pthread_create(&philo[i].philo_thread, NULL, b2b_philo, (void *)&philo[i]);
		usleep(500000);
		i++;
	}
	while (1)
	{
		sleep(1);
	}
}
