/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 18:00:41 by omartine          #+#    #+#             */
/*   Updated: 2022/05/30 19:17:36 by omartine         ###   ########.fr       */
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
# include <sys/time.h>
# include <pthread.h>
# include "philo_structs.h"

int		ft_atoi(const char *str);
char	*ft_itoa(int n);
int		ft_strlen(char *str);

t_terms	*init_terms(int argc, char **argv);
t_philo	*init_philo(t_terms *philo_terms);
void	philo_handler(t_philo *philo, t_terms *philo_terms);

void	*socrates(void *arg);
void	*platon(void *arg);

int		philo_eat(t_philo *philo);
int		philo_sleep(t_philo *philo);
void	philo_dead(t_philo *philo);

void	print_philo_state(t_philo *philo, int state);
void	*check_end_simulation(void	*arg);
int		check_time(t_philo *philo, t_terms *philo_terms);
void	check_philo_state(t_philo *philo, t_terms *philo_terms);

void	leaks(void);

#endif
