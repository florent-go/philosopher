/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez <fgomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 11:30:17 by fgomez            #+#    #+#             */
/*   Updated: 2021/06/17 11:08:53 by fgomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_mutex(t_p *p)
{
	int	i;

	pthread_mutex_init(&p->write, NULL);
	pthread_mutex_init(&p->dead, NULL);
	pthread_mutex_lock(&p->dead);
	p->forks = malloc(sizeof((p->forks)) * p->number);
	if (!(p->forks))
		return (1);
	i = 0;
	while (i < p->number)
		pthread_mutex_init(&p->forks[i++], NULL);
	return (0);
}

void	init_philos(t_p *p)
{
	int	i;

	i = 0;
	while (i < p->number)
	{
		p->philos[i].position = i;
		p->philos[i].p = p;
		p->philos[i].time = p->start;
		if (i - 1 < 0)
			p->philos[i].lfork = &p->forks[p->number - 1];
		else
			p->philos[i].lfork = &p->forks[i - 1];
		p->philos[i].rfork = &p->forks[i];
		pthread_mutex_init(&p->philos[i].mutex, NULL);
		i++;
	}
}

int	init_struct(t_p *p, int ac, char **av)
{
	if (check_arg(ac, av) == 1)
		return (1);
	p->start = get_time();
	p->number = ft_atoi(av[1]);
	p->ttd = ft_atoi(av[2]);
	p->tte = ft_atoi(av[3]);
	p->tts = ft_atoi(av[4]);
	if (ac == 6)
		p->mec = ft_atoi(av[5]);
	else
		p->mec = 0;
	if (2 > p->number || 200 < p->number || 0 > p->mec || 0 > p->tte
		|| 0 > p->tte || 0 > p->tts || 0 > p->ttd)
		return (1);
	p->philos = (t_philo *)malloc(sizeof(*(p->philos)) * p->number + 1);
	if (!(p->philos))
		return (1);
	if (init_mutex(p) != 0)
		return (1);
	init_philos(p);
	return (0);
}
