/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 13:16:22 by saoh              #+#    #+#             */
/*   Updated: 2021/07/01 18:48:45 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
/*
void		pickup_forks(int p_n, t_ph *ph)
{
	while (ph->forks[p_n % ph->n_o_p] == 0)
		usleep(50);
	pthread_mutex_lock(&ph->mutexes[p_n % ph->n_o_p]);
	ph->forks[p_n % ph->n_o_p] = 0;
	pthread_mutex_unlock(&ph->mutexes[p_n % ph->n_o_p]);
}

void		return_forks(int p_n, t_ph *ph)
{
	pthread_mutex_lock(&ph->mutexes[p_n % ph->n_o_p]);
	ph->forks[p_n % ph->n_o_p] = 1;
	pthread_mutex_unlock(&ph->mutexes[p_n % ph->n_o_p]);
}
*/
void		oddphilo(t_ph *ph)
{
	while (1)
	{
		if (ph->p_d->p_d_f == 1)
			break ;
	}
	printf("end %d philo\n", ph->p_n);
}

void		*philoso(void *arg)
{
	t_ph	*ph;

	ph = (t_ph *)arg;
	if (ph->p_d->p_d_f == 1)
		return (NULL);
	gettimeofday(&ph->tv, NULL);
	if (ph->tv.tv_usec - ph->p_d->f_tv.tv_usec > ph->p_d->arg->t_t_d)
	{
		ph->p_d->p_d_f = 1;
		printf("%dms %d philo died\n", ph->tv.tv_usec, ph->p_n);
		return (NULL);
	}
	oddphilo(ph);
	return (NULL);
}

void		philo(t_ph *ph, pthread_t *t, pthread_mutex_t *mutexes)
{
	int		i;

	i = -1;
	while (++i < ph[0].p_d->arg->n_o_p)
	{
		pthread_mutex_init(&mutexes[i], NULL);
		ph[0].p_d->forks[i] = 1;
	}
	i = -1;
	gettimeofday(&ph[0].p_d->f_tv, NULL);
	while (++i < ph[0].p_d->arg->n_o_p)
		pthread_create(&t[i], NULL, philoso, (void *)&ph[i]);
	i = -1;
	while (++i < ph[0].p_d->arg->n_o_p)
		pthread_join(t[i], NULL);
	i = -1;
	while (++i < ph[0].p_d->arg->n_o_p)
		pthread_mutex_destroy(&mutexes[i]);
}
