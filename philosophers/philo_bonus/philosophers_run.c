/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_run.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 15:36:55 by saoh              #+#    #+#             */
/*   Updated: 2021/09/20 17:33:19 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	pickup_forks(t_ph *ph)
{
	long	c_time;

	sem_wait(ph->p_d->forks);
	c_time = get_time();
	print_state(c_time - ph->p_d->first_time, ph, "has taken fork");
	sem_wait(ph->p_d->forks);
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
	if (ph->eat_c == ph->p_d->n_o_t)
		sem_post(ph->eat_end);
	eat_end_time = c_time + ph->p_d->t_t_e;
	while (c_time < eat_end_time)
	{
		usleep(500);
		c_time = get_time();
	}
	sem_post(ph->p_d->forks);
	sem_post(ph->p_d->forks);
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
	print_state(c_time - ph->p_d->first_time, ph, "is tkinking");
}

void	each_philo(t_ph *ph)
{
	pthread_t	t;

	ph->eat_time = ph->p_d->first_time;
	pthread_create(&t, NULL, philoso_moniter, (void *)ph);
	pthread_detach(t);
	while (1)
	{
		pickup_forks(ph);
		eating_philo(ph);
		sleeping_philo(ph);
	}
}
