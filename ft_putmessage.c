/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmessage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez <fgomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 09:02:43 by fgomez            #+#    #+#             */
/*   Updated: 2021/06/18 09:01:04 by fgomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	display_message(t_philo *philo, int flag)
{
	unsigned long long	time;

	pthread_mutex_lock(&philo->p->write);
	time = get_time() - philo->p->start;
	if (flag == 1)
		printf("%llu\t%d is eating\n", time, philo->position + 1);
	if (flag == 2)
		printf("%llu\t%d is thinking\n", time, philo->position + 1);
	if (flag == 3)
		printf("%llu\t%d is sleeping\n", time, philo->position + 1);
	if (flag == 4)
	{
		printf("%llu\t%d died\n", time, philo->position + 1);
		return (1);
	}
	if (flag == 5)
		printf("%llu\t%d has taken a fork\n", time, philo->position + 1);
	if (flag == 6)
	{
		printf("finish eat\n");
		return (1);
	}
	pthread_mutex_unlock(&philo->p->write);
	return (0);
}
