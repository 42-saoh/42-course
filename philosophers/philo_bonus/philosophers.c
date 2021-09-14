/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 13:16:22 by saoh              #+#    #+#             */
/*   Updated: 2021/09/14 18:59:49 by saoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


static void	philo2(t_ph *ph)
{
	int		i;
	pid_t	p;

	i = 0;
	p = waitpid(-1, NULL, 0);
	while (i < ph[0].p_d->n_o_p)
	{
		if (p != ph[i].p_pid)
			kill(ph[i].p_pid, SIGKILL);
		i++;
	}
	sem_post(ph->p_d->msg);
}

void	philo(t_ph *ph)
{
	int			i;
	pthread_t	t;

	i = 0;
	pthread_create(&t, NULL, eat_moniter, (void *)ph);
	pthread_detach(t);
	ph[0].p_d->first_time = get_time();
	while (i < ph[0].p_d->n_o_p)
	{
		ph[i].p_pid = fork();
		if (ph[i].p_pid == 0)
		{
			each_philo(&ph[i]);
			exit(0);
		}
		i++;
	}
	philo2(ph);
}
