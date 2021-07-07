/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_run.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 15:36:55 by saoh              #+#    #+#             */
/*   Updated: 2021/07/07 14:12:11 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	pickup_forks(t_ph *ph, int p_n)
{
	long	c_time;

	pthread_mutex_lock(&ph->p_d->mutexes[p_n % ph->p_d->n_o_p]);
	c_time = get_time();
	write_state((int)(c_time - ph->first_time), ph, " has taken fork\n", 16);
}

static void	eating_philo(t_ph *ph)
{
	long	eat_end_time;

	ph->eat_time = get_time();
	ph->eat_flag = 1;
	write_state(ph->eat_time - ph->first_time, ph, " is eating\n", 11);
	eat_end_time = ph->eat_time + ph->p_d->t_t_e;
	while (ph->eat_time < eat_end_time)
	{
		usleep(20);
		ph->eat_time = get_time();
	}
	ph->eat_flag = 0;
	pthread_mutex_unlock(&ph->p_d->mutexes[ph->p_n % ph->p_d->n_o_p]);
	pthread_mutex_unlock(&ph->p_d->mutexes[(ph->p_n + 1) % ph->p_d->n_o_p]);
}

static void	sleeping_philo(t_ph *ph)
{
	long	c_time;
	long	sleep_time;

	c_time = get_time();
	write_state(c_time - ph->first_time, ph, " is sleeping\n", 13);
	sleep_time = c_time + ph->p_d->t_t_s;
	while (c_time < sleep_time)
	{
		usleep(20);
		c_time = get_time();
	}
	c_time = get_time();
	write_state(c_time - ph->first_time, ph, " is thinking\n", 13);
}

void	evenphilo(t_ph *ph)
{
	while (1)
	{
		pickup_forks(ph, ph->p_n + 1);
		pickup_forks(ph, ph->p_n);
		eating_philo(ph);
		sleeping_philo(ph);
	}
}

void	oddphilo(t_ph *ph)
{
	while (1)
	{
		pickup_forks(ph, ph->p_n);
		pickup_forks(ph, ph->p_n + 1);
		eating_philo(ph);
		sleeping_philo(ph);
	}
}
