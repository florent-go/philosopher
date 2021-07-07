/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez <fgomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 11:18:36 by fgomez            #+#    #+#             */
/*   Updated: 2021/06/17 11:07:08 by fgomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_arg(int ac, char **av)
{
	int	i;
	int	j;

	j = 1;
	while (j < ac)
	{
		i = 0;
		while (av[j][i])
		{
			if (ft_isdigit(av[j][i]) == 0)
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}

int	ft_error(char *str)
{
	ft_putstr_fd(str, 1);
	return (1);
}

int	clear_all(t_p *p)
{
	if (p->forks)
		free(p->forks);
	if (p->philos)
		free(p->philos);
	return (0);
}
