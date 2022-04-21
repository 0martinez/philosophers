/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 12:52:29 by omartine          #+#    #+#             */
/*   Updated: 2022/04/21 13:50:28 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <pthread.h>

# define TRUE 1
# define FALSE 0

typedef struct s_ph
{
	int	num_of_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	num_of_eats;

}	t_ph;

typedef struct s_philo
{
	int				id;
	pthread_mutex_t	right_fork;
	pthread_mutex_t	left_fork;
	t_philo			*next_philo;
	t_philo			*last_philo;
}	t_philo;


int	ft_atoi(const char *str);

#endif
