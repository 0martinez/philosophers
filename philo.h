/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 12:52:29 by omartine          #+#    #+#             */
/*   Updated: 2022/05/13 19:04:11 by omartine         ###   ########.fr       */
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
# include "philo_struct.h"

# define TRUE 1
# define FALSE 0

int		ft_atoi(const char *str);
int		ft_strlen(char *str);
void	ft_putstr(char *str);

void	philo_dance(t_philo *philo, t_terms *philo_terms);
int		philo_sleep(t_philo philo, struct timeval *timer);
void	print_philo_state(t_philo *philo, int state);
void	philo_eat(t_philo *philo);
char	*ft_itoa(int n);

#endif
