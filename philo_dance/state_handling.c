/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 19:12:07 by omartine          #+#    #+#             */
/*   Updated: 2022/05/30 19:40:22 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	philo_dead(t_philo *philo)
{
	gettimeofday(&philo->timer2, NULL);
	printf(RED"☠  %ldms Philosopher --%d-- died\033[0m ☠	",
		((philo->timer2.tv_sec - philo->timer1.tv_sec) * 1000)
		+ ((philo->timer2.tv_usec - philo->timer1.tv_usec) / 1000),
		philo->id + 1);
	exit(0);
}

void	*check_end_simulation(void	*arg)
{
	t_philo	*philo;
	int		n_philo;
	int		i;
	int		flg;

	philo = (t_philo *)arg;
	n_philo = philo->philo_terms.num_of_philo;
	while (philo)
	{
		i = 0;
		flg = 0;
		while (i < n_philo)
		{
			if (philo->state == OUT)
				flg++;
			i++;
			philo = philo->r_philo;
		}
		if (flg == n_philo)
		{
			printf(WHITE"\n---END OF SIMULATION---");
			exit (0);
		}
	}
	return (0);
}

int	check_time(t_philo *philo, t_terms *philo_terms)
{
	gettimeofday(&philo->check, NULL);
	if (philo->state != EATING
		&& ((philo->check.tv_sec - philo->start_time.tv_sec) * 1000)
		+ ((philo->check.tv_usec - philo->start_time.tv_usec) / 1000)
		>= philo_terms->time_to_die)
	{
		return (1);
	}
	return (0);
}

void	check_philo_state(t_philo *philo, t_terms *philo_terms)
{
	pthread_t	check_simu;

	pthread_create(&check_simu, NULL, check_end_simulation, (void *)philo);
	while (philo)
	{
		if ((philo->state != EATING && philo->state != OUT)
			&& check_time(philo, philo_terms) == 1)
			philo_dead(philo);
		philo = philo->r_philo;
	}
}
