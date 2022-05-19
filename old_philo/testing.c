/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:32:41 by omartine          #+#    #+#             */
/*   Updated: 2022/05/11 19:02:27 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


/*
void	*flako(void *xd)
{
	t_testing	*tst;

	tst = (t_testing *) xd;
	while (1)
	{
		if (tst->id == 1)
		{
			if (tst->siguiente->hola == 10)
			{
				tst->hola = 9;
			}
		}
		if (tst->id == 2)
		{
			write(1, ft_itoa(tst->last->hola), 1);
			write(1, "pulse para ver algo chido", 25);
			getchar();
			tst->hola = 10;
		}

	}
	return (0);
}*/

void	leaks(void)
{
	system("leaks -q a.out");
}

typedef struct testing
{
	int				id;
	int				testing;
	struct testing	*siguiente;
	struct testing	*last;
	pthread_t		philo_thread;
}	t_testing;


int	main(void)
{
	t_testing	*tst;
	t_testing	*aux;
	int			i;

	i = 0;
	tst = malloc (sizeof(t_testing));
	while (i < 3)
	{
		//tst = malloc (sizeof(t_testing));
		tst->siguiente = malloc (sizeof(t_testing));
		tst->id = i;
		if (tst->id == 0)
			aux = tst;
		if (i == 2)
		{
			tst->siguiente = aux;
			tst->siguiente->last = tst;
		}
		else
		{
			tst->siguiente->last = tst;
		}
		printf("%d", tst->id);
		tst = tst->siguiente;
		i++;
	}
	//atexit(leaks);
	//tst = malloc (sizeof(t_testing));
	//tst->siguiente = malloc (sizeof(t_testing));
	//tst->id = 1;
	//tst->siguiente->id = 2;
	//tst->hola = 7;
	//tst->siguiente->last = tst;
	//tst->siguiente->siguiente = NULL;
	//tst->siguiente->hola = 5;
	/*pthread_create(&tst->philo_thread, NULL, flako, (void *)tst);
	tst = tst->siguiente;
	pthread_create(&tst->philo_thread, NULL, flako, (void *)tst);
	while (1)
	{
		sleep(1);
	}*/
	i = 0;
	while (i < 9)
	{
		printf("%d", tst->id);
		tst = tst->siguiente;
		i++;
	}
	printf("reverse");
	getchar();
	i = 0;
	while (i < 9)
	{
		printf("%d", tst->id);
		tst = tst->last;
		i++;
	}
	
	return (0);
}
