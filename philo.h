/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez <fgomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 11:20:44 by fgomez            #+#    #+#             */
/*   Updated: 2021/06/17 11:14:13 by fgomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_p		t_p;
typedef struct s_philo
{
	int					position;
	int					is_eating;
	int					eat_count;
	pthread_mutex_t		*lfork;
	pthread_mutex_t		*rfork;
	pthread_mutex_t		mutex;
	t_p					*p;
	unsigned long long	time;
}						t_philo;

typedef struct s_p
{
	unsigned long long	ttd;
	unsigned long long	tte;
	unsigned long long	tts;
	int					mec;
	unsigned long long	start;
	int					number;
	pthread_mutex_t		*forks;
	pthread_mutex_t		dead;
	pthread_mutex_t		write;

	t_philo				*philos;
}						t_p;
/*
*					Check + Error
*/
int					ft_error(char *str);
int					clear_all(t_p *p);
int					check_arg(int ac, char **av);
/*
*					Routine
*/
void				for_eat(t_philo *philos);
void				go_sleep(t_philo *philo);
void				lock_fork(t_philo *philos);
/*
*					init
*/
int					init_struct(t_p *p, int ac, char **av);
/*
*					ft_putchar
*/
int					display_message(t_philo *philo, int flag);
/*
*					Time to die
*/
unsigned long long	get_time(void);
/*
*					Utils
*/
void				ft_putstr_fd(char *s, int fd);
void				ft_putnbr_fd(unsigned long long n, int fd);
int					ft_atoi(const char *str);
void				ft_putchar_fd(char c, int fd);
int					ft_isdigit(int c);

#endif