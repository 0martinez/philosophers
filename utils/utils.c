/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartine <omartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 19:23:14 by omartine          #+#    #+#             */
/*   Updated: 2022/05/20 19:25:23 by omartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_atoi(const char *str)
{
	int	num;
	int	i;

	i = 0;
	num = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	if (str[i] != 0)
	{
		write(1, "Error", 5);
		exit(0);
	}
	return (num);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

static void	aux_itoa(long n, int j, char *aux)
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
	aux_itoa(sb, j - 1, aux);
	aux[j - 1] = 0;
	return (aux);
}

