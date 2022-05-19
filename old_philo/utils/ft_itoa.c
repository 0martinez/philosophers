/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:37:02 by omartine          #+#    #+#             */
/*   Updated: 2022/04/27 17:37:19 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	ft_aux(long n, int j, char *aux)
{
	if (n == 0)
		aux[j - 1] = '0';
	while (n != 0)
	{
		aux[j-- - 1] = (n % 10) + '0';
		n = n / 10;
	}
}

char	*ft_itoa(int n)
{
	char	*aux;
	long	i;
	int		j;
	long	sb;

	j = 1;
	i = 1;
	sb = n;
	if (n <= 0 && j++ != -1)
		sb = sb * -1;
	while (i <= sb && j++ != -1)
		i = 10 * i;
	aux = (char *) malloc (sizeof(char) * (j));
	if (!aux)
		return (0);
	if (n < 0)
		aux[0] = '-';
	ft_aux(sb, j - 1, aux);
	aux[j - 1] = 0;
	return (aux);
}
