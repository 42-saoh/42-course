/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 13:16:22 by saoh              #+#    #+#             */
/*   Updated: 2021/07/07 14:06:00 by saoh             ###   ########.fr       */
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
		pthread_mutex_init(&p_d->mutexes[i++], NULL);
	pthread_mutex_lock(&p_d->end_mutex);
}

static void	destroy_mutexes(t_p_data *p_d)
{
	int			n_o_p;
	int			i;

	i = 0;
	n_o_p = p_d->n_o_p;
	pthread_mutex_destroy(&p_d->end_mutex);
	pthread_mutex_destroy(&p_d->msg_mutex);
	while (i < n_o_p)
		pthread_mutex_destroy(&p_d->mutexes[i++]);
}

static void	*philoso(void *arg)
{
	t_ph		*ph;
	pthread_t	t;

	ph = (t_ph *)arg;
	ph->first_time = get_time();
	ph->eat_time = ph->first_time;
	pthread_create(&t, NULL, philoso_moniter, (void *)ph);
	pthread_detach(t);
	if (ph->p_n % 2)
		oddphilo(ph);
	else
		evenphilo(ph);
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
