/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 17:59:59 by omartine          #+#    #+#             */
/*   Updated: 2022/05/28 19:19:02 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_terms	*philo_terms;
	t_philo	*philo;

	philo_terms = init_terms(argc, argv);
	philo = init_philo(philo_terms);
	philo_handler(philo, philo_terms);
	return (0);
}
