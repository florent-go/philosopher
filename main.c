/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez <fgomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 11:15:02 by fgomez            #+#    #+#             */
/*   Updated: 2021/06/17 11:35:24 by fgomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*is_dead(void *ok)
{
	t_philo		*philos;

	philos = (t_philo *)ok;
	while (1)
	{
		if (!philos->is_eating && (get_time() - philos->time) >= philos->p->ttd)
		{
			display_message(philos, 4);
			pthread_mutex_unlock(&philos->p->dead);
			return ((void *)1);
		}
		else if (philos->eat_count == philos->p->mec && philos->p->mec != 0)
		{
			display_message(philos, 6);
			pthread_mutex_unlock(&philos->p->dead);
			return ((void *)1);
		}
		usleep(500);
	}
}

static void	*routine(void *ok)
{
	t_philo		*philos;
	pthread_t	th;

	philos = (t_philo *)ok;
	philos->time = get_time();
	if (pthread_create(&th, NULL, is_dead, philos))
		return ((void *)1);
	pthread_detach(th);
	while (1)
	{
		lock_fork(philos);
		for_eat(philos);
		go_sleep(philos);
		display_message(philos, 2);
	}
	return ((void *)0);
}

void	pthread_excve_part2(t_p *p)
{
	int			i;
	void		*philo;
	pthread_t	th;

	i = -1;
	while (++i < p->number)
	{
		if (!(i % 2))
		{
			philo = (void *)(&p->philos[i]);
			if (pthread_create(&th, NULL, &routine, philo) != 0)
				ft_error("Error: pthread_create\n");
			pthread_detach(th);
			usleep(100);
		}
	}
}

void	pthread_excve(t_p *p)
{
	pthread_t	th;
	void		*philo;
	int			i;

	i = -1;
	while (++i < p->number)
	{
		if (i % 2)
		{
			philo = (void *)(&p->philos[i]);
			if (pthread_create(&th, NULL, &routine, philo) != 0)
				ft_error("Error: pthread_create\n");
			pthread_detach(th);
			usleep(100);
		}
	}
	pthread_excve_part2(p);
}

int	main(int ac, char **av)
{
	t_p	p;

	if (ac < 5 || ac > 6)
		return (ft_error("Error: bad arguments\n") + clear_all(&p));
	if (init_struct(&p, ac, av) != 0)
		return (ft_error("Error: struct not init\n"));
	pthread_excve(&p);
	pthread_mutex_lock(&p.dead);
	pthread_mutex_unlock(&p.dead);
	clear_all(&p);
	return (0);
}
