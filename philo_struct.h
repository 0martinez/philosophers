/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 18:32:57 by omartine          #+#    #+#             */
/*   Updated: 2022/04/23 20:25:13 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_STRUCT_H
# define PHILO_STRUCT_H

# include "philo.h"

# define TRUE 1
# define FALSE 0

# define EATING 0
# define SLEEPING 1
# define THINKING 2
# define DISABLED 0

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
	int				state_of_philo;
	int				r_fork_position;
	int				l_fork_position;
	pthread_t		philo_thread;
	pthread_mutex_t	left_fork;
	pthread_mutex_t	righ_fork;
	struct s_terms	philo_terms;
}	t_philo;

#endif
