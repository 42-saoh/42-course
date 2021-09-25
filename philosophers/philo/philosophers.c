/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 13:16:22 by saoh              #+#    #+#             */
/*   Updated: 2021/09/25 18:13:36 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	init_mutexes(t_p_data *p_d)
{
	int			n_o_p;
	int			i;

	i = 0;
	n_o_p = p_d->n_o_p;
	pthread_mutex_init(&p_d->start_mutex, NULL);
	while (i < n_o_p)
	{
		p_d->forks[i] = 1;
		pthread_mutex_init(&p_d->mutexes[i], NULL);
		i++;
	}
	pthread_mutex_lock(&p_d->start_mutex);
}

static void	destroy_mutexes(t_p_data *p_d)
{
	int			n_o_p;
	int			i;

	i = 0;
	n_o_p = p_d->n_o_p;
	pthread_mutex_destroy(&p_d->start_mutex);
	while (i < n_o_p)
		pthread_mutex_destroy(&p_d->mutexes[i++]);
}

static void	philoso_2(t_ph *ph)
{
	long	i;

	i = 0;
	while (i++ < 500)
		usleep(50);
	oddphilo(ph);
}

static void	*philoso(void *arg)
{
	t_ph		*ph;
	pthread_t	t;

	ph = (t_ph *)arg;
	ph->eat_time = get_time();
	if (ph->p_n == ph->p_d->n_o_p - 1)
	{
		ph->p_d->first_time = get_time();
		pthread_create(&t, NULL, philoso_moniter, ph - (ph->p_d->n_o_p - 1));
		pthread_detach(t);
		pthread_mutex_unlock(&ph->p_d->start_mutex);
	}
	pthread_mutex_lock(&ph->p_d->start_mutex);
	pthread_mutex_unlock(&ph->p_d->start_mutex);
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
		pthread_create(&ph->p_d->pt[i], NULL, philoso, (void *)&ph[i]);
		i++;
	}
	while (i--)
		pthread_join(ph->p_d->pt[i], NULL);
	destroy_mutexes(ph->p_d);
}
