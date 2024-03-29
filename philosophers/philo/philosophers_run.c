/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_run.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 15:36:55 by saoh              #+#    #+#             */
/*   Updated: 2021/09/20 17:13:52 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	pickup_forks(t_ph *ph, int p_n)
{
	long	c_time;

	pthread_mutex_lock(&ph->p_d->mutexes[p_n % ph->p_d->n_o_p]);
	ph->p_d->forks[p_n % ph->p_d->n_o_p] = 0;
	c_time = get_time();
	print_state(c_time - ph->p_d->first_time, ph, "has taken fork");
}

static void	eating_philo(t_ph *ph)
{
	long	eat_end_time;
	long	c_time;

	c_time = get_time();
	ph->eat_time = c_time;
	print_state(c_time - ph->p_d->first_time, ph, "is eating");
	ph->eat_c++;
	eat_end_time = ph->eat_time + ph->p_d->t_t_e;
	while (c_time < eat_end_time)
	{
		c_time = get_time();
		usleep(500);
	}
	pthread_mutex_unlock(&ph->p_d->mutexes[ph->p_n % ph->p_d->n_o_p]);
	ph->p_d->forks[ph->p_n % ph->p_d->n_o_p] = 1;
	pthread_mutex_unlock(&ph->p_d->mutexes[(ph->p_n + 1) % ph->p_d->n_o_p]);
	ph->p_d->forks[(ph->p_n + 1) % ph->p_d->n_o_p] = 1;
}

static void	sleeping_philo(t_ph *ph)
{
	long	c_time;
	long	sleep_time;

	c_time = get_time();
	print_state(c_time - ph->p_d->first_time, ph, "is sleeping");
	sleep_time = c_time + ph->p_d->t_t_s;
	while (c_time < sleep_time)
	{
		usleep(500);
		c_time = get_time();
	}
	print_state(c_time - ph->p_d->first_time, ph, "is thinking");
}

void	oddphilo(t_ph *ph)
{
	while (!ph->p_d->die_flag)
	{
		pickup_forks(ph, ph->p_n);
		pickup_forks(ph, ph->p_n + 1);
		eating_philo(ph);
		sleeping_philo(ph);
	}
}
