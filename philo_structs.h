/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_structs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 18:03:54 by omartine          #+#    #+#             */
/*   Updated: 2022/05/19 19:04:38 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_STRUCTS_H
# define PHILO_STRUCTS_H

# include "philo.h"

# define TRUE 1
# define FALSE 0

# define ALIVE -1
# define EATING 0
# define SLEEPING 1
# define THINKING 2
# define DISABLED 0
# define DEAD 3
# define RIGHT_FORK 5
# define LEFT_FORK 6
# define RIGHT_FORK_LEFT 7
# define LEFT_FORK_LEFT 8

typedef struct s_terms
{
	int				num_of_philo;
	double			time_to_die;
	double			time_to_eat;
	double			time_to_sleep;
	int				num_of_eats;
}	t_terms;

typedef struct s_philo
{
	int				id;
	int				state;
	struct timeval	timer1;
	struct timeval	timer2;
	pthread_t		philo_thread;
	pthread_mutex_t	*fork;
	struct s_philo	*r_philo;
	struct s_terms	*philo_terms;
}	t_philo;

#endif
