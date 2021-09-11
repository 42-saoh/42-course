/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 13:16:22 by saoh              #+#    #+#             */
/*   Updated: 2021/09/11 16:13:41 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	init_mutexes(t_p_data *p_d)
{
	int			n_o_p;
	int			i;

	i = 0;
	n_o_p = p_d->n_o_p;
	pthread_mutex_init(&p_d->msg_mutex, NULL);
	pthread_mutex_init(&p_d->end_mutex, NULL);
	pthread_mutex_init(&p_d->start_mutex, NULL);
	while (i < n_o_p)
	{
		p_d->forks[i] = 1;
		pthread_mutex_init(&p_d->mutexes[i], NULL);
		i++;
	}
	pthread_mutex_lock(&p_d->end_mutex);
	pthread_mutex_lock(&p_d->start_mutex);
}

static void	destroy_mutexes(t_p_data *p_d)
{
	int			n_o_p;
	int			i;

	i = 0;
	n_o_p = p_d->n_o_p;
	pthread_mutex_destroy(&p_d->end_mutex);
	pthread_mutex_destroy(&p_d->start_mutex);
	while (i < n_o_p)
		pthread_mutex_destroy(&p_d->mutexes[i++]);
	pthread_mutex_unlock(&p_d->msg_mutex);
	pthread_mutex_destroy(&p_d->msg_mutex);
}

static void	philoso_2(t_ph *ph)
{
	ph->start_sec = get_time() - ph->p_d->first_time;
	while (ph->start_sec < 20000)
	{
		ph->start_sec += 50;
		usleep(50);
	}
	oddphilo(ph);
}

static void	*philoso(void *arg)
{
	t_ph		*ph;
	pthread_t	t;

	ph = (t_ph *)arg;
	if (ph->p_n == ph->p_d->n_o_p - 1)
	{
		ph->p_d->first_time = get_time();
		pthread_mutex_unlock(&ph->p_d->start_mutex);
	}
	pthread_mutex_lock(&ph->p_d->start_mutex);
	pthread_mutex_unlock(&ph->p_d->start_mutex);
	pthread_create(&t, NULL, philoso_moniter, ph);
	pthread_detach(t);
	ph->eat_time = ph->p_d->first_time;
	if (ph->p_n % 2 == 0)
		oddphilo(ph);
	else
		philoso_2(ph);
	return (NULL);
}

void	philo(t_ph *ph)
{
	int			i;
	int			n_o_p;
	pthread_t	t;

	i = 0;
	n_o_p = ph[0].p_d->n_o_p;
	init_mutexes(ph->p_d);
	pthread_create(&t, NULL, eat_moniter, (void *)ph);
	pthread_detach(t);
	while (i < n_o_p)
	{
		pthread_create(&t, NULL, philoso, (void *)&ph[i]);
		pthread_detach(t);
		i++;
	}
	pthread_mutex_lock(&ph->p_d->end_mutex);
	pthread_mutex_unlock(&ph->p_d->end_mutex);
	destroy_mutexes(ph->p_d);
}
