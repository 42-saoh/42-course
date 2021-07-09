/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 13:16:22 by saoh              #+#    #+#             */
/*   Updated: 2021/07/09 16:14:10 by saoh             ###   ########.fr       */
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
	while (i < n_o_p)
	{
		p_d->forks[i] = 1;
		pthread_mutex_init(&p_d->mutexes[i], NULL);
		i++;
	}
	pthread_mutex_lock(&p_d->end_mutex);
}

static void	destroy_mutexes(t_p_data *p_d)
{
	int			n_o_p;
	int			i;

	i = 0;
	n_o_p = p_d->n_o_p;
	pthread_mutex_destroy(&p_d->end_mutex);
	while (i < n_o_p)
		pthread_mutex_destroy(&p_d->mutexes[i++]);
	pthread_mutex_unlock(&p_d->msg_mutex);
	pthread_mutex_destroy(&p_d->msg_mutex);
}

static void	*philoso(void *arg)
{
	t_ph		*ph;
	pthread_t	t;

	ph = (t_ph *)arg;
	ph->eat_time = ph->p_d->first_time;
	pthread_create(&t, NULL, philoso_moniter, (void *)ph);
	pthread_detach(t);
	oddphilo(ph);
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
	ph[0].p_d->first_time = get_time();
	while (i < n_o_p)
	{
		pthread_create(&t, NULL, philoso, (void *)&ph[i]);
		pthread_detach(t);
		usleep(100);
		i++;
	}
	pthread_mutex_lock(&ph->p_d->end_mutex);
	pthread_mutex_unlock(&ph->p_d->end_mutex);
	destroy_mutexes(ph->p_d);
}
