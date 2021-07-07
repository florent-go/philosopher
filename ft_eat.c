/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez <fgomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 14:11:30 by fgomez            #+#    #+#             */
/*   Updated: 2021/06/17 11:06:41 by fgomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	lock_fork(t_philo *philos)
{
	pthread_mutex_lock(philos->lfork);
	display_message(philos, 5);
	pthread_mutex_lock(philos->rfork);
	display_message(philos, 5);
}

void	for_eat(t_philo *philos)
{
	pthread_mutex_lock(&philos->mutex);
	philos->is_eating = 1;
	philos->time = get_time();
	display_message(philos, 1);
	usleep(philos->p->tte * 1000);
	philos->eat_count++;
	philos->is_eating = 0;
	pthread_mutex_unlock(&philos->mutex);
}

void	go_sleep(t_philo *philos)
{
	pthread_mutex_unlock(philos->lfork);
	pthread_mutex_unlock(philos->rfork);
	display_message(philos, 3);
	usleep(philos->p->tts * 1000);
}
